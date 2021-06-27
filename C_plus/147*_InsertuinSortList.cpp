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
    ListNode *insertionSortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *cur = new ListNode(-5001), *ret = cur;
        ListNode *p = head;
        while (p)
        {
            ListNode *last = p->next;

            while (cur->next && cur->next->val <= p->val)
                cur = cur->next;
            p->next = cur->next;
            cur->next = p;
            p = last;
            cur = ret;
        }
        return ret->next;
    }
};