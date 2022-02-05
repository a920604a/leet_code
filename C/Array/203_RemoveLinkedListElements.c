/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *removeElements(struct ListNode *head, int val)
{
    if (!head)
        return NULL;
    struct ListNode *ret = (struct ListNode *)malloc(sizeof(struct ListNode));
    ret->next = head;
    ret->val = -1;
    struct ListNode *slow = ret, *fast = head;
    while (fast)
    {
        if (fast->val != val)
        {
            slow->next = fast;
            slow = slow->next;
        }
        fast = fast->next;
    }
    slow->next = NULL;
    return ret->next;
}