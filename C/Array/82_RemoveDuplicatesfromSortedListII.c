/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *deleteDuplicates(struct ListNode *head)
{
    if (!head)
        return NULL;
    struct ListNode *ret = (struct ListNode *)malloc(sizeof(struct ListNode));
    ret->val = -101;
    ret->next = head;
    struct ListNode *slow;
    slow = ret;
    while (slow->next)
    {
        struct ListNode *fast = slow->next;
        while (fast->next && fast->val == fast->next->val)
            fast = fast->next;
        if (slow->next == fast)
            slow = slow->next;
        else
            slow->next = fast->next;
    }
    return ret->next;
}