/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *deleteDuplicates(struct ListNode *head)
{
    if (!head || !head->next)
        return head;
    struct ListNode *slow = head, *fast = head;
    while (fast)
    {
        if (fast->val != slow->val)
        {
            slow->next = fast;
            slow = slow->next;
        }
        fast = fast->next;
    }
    slow->next = NULL;
    return head;
}