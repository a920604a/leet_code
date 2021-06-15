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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL && l2 == NULL)
            return NULL;
        ListNode *ret = new ListNode();
        ListNode *p = ret;

        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        while (l1 && l2)
        {
            ret->next = new ListNode();
            ret = ret->next;
            if (l1->val < l2->val)
            {
                ret->val = l1->val;
                l1 = l1->next;
            }
            else
            {
                ret->val = l2->val;
                l2 = l2->next;
            }
        }
        if (l1)
            ret->next = l1;
        if (l2)
            ret->next = l2;
        return p->next;
    }
};