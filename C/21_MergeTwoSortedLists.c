/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    if (!l1 && !l2)
        return NULL;
    struct ListNode *ret = malloc(sizeof(struct ListNode)), *ans = ret;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            ret->next = l1;
            l1 = l1->next;
        }
        else
        {
            ret->next = l2;
            l2 = l2->next;
        }

        ret = ret->next;
    }
    if (l1)
        ret->next = l1;
    if (l2)
        ret->next = l2;
    return ans->next;
}