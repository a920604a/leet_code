/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        // option 1  O(N) time
        if (!head)
            return head;
        ListNode *pre = new ListNode(-1), *ret = pre;
        ret->next = head;
        ListNode *p1 = new ListNode(-1), *p2 = new ListNode(-1), *p3 = new ListNode(-1);
        ListNode *a = p1, *b = p2, *c = p3;
        stack<int> s;
        int l = 1;
        for (ListNode *p = head; p; p = p->next, l++)
        {
            if (l < left)
            {
                p1->next = new ListNode(p->val);
                p1 = p1->next;
            }
            else if (l >= left && l <= right)
            {

                s.push(p->val);
            }
            else
            {
                p3->next = new ListNode(p->val);
                p3 = p3->next;
            }
        }
        // reverse p2
        while (!s.empty())
        {
            p2->next = new ListNode(s.top());
            s.pop();
            p2 = p2->next;
        }

        // concatenate
        p1->next = b->next;
        p2->next = c->next;
        return a->next;
    }
};