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
    void reorderList(ListNode *head)
    {
        // 1. slow-fast to find middle point
        // 2. reverse the scond linked list
        // 3. merge list 1 and list 2
        if (!head || !head->next)
            return;

        ListNode *slow = head, *fast = head, *pre = nullptr;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = nullptr;

        for (ListNode *p = head; p; p = p->next)
            cout << p->val << " ";
        cout << endl;
        for (ListNode *p = slow; p; p = p->next)
            cout << p->val << " ";
        cout << endl;

        // 2. reverse linked list
        pre = nullptr;
        ListNode *cur = slow, *post = slow->next;
        while (post)
        {
            cur->next = pre;
            pre = cur;
            cur = post;
            post = post->next;
        }

        cur->next = pre;

        // 3. merge tow linked list
        ListNode *s1 = head->next, *s2 = cur;
        ListNode *ret = head;
        // ListNode *merge = new ListNode(0), *ret = merge;

        while (s1 || s2)
        {

            if (s2)
            {
                ret->next = s2;
                s2 = s2->next;
                ret = ret->next;
            }

            if (s1)
            {
                ret->next = s1;
                s1 = s1->next;
                ret = ret->next;
            }
        }
    }
};