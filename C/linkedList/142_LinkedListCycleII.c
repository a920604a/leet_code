/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head)
{
    if (!head)
        return NULL;
    struct ListNode *slow, *fast;
    slow = fast = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
            break;
    }
    if (fast == NULL || fast->next == NULL)
        return false;
    slow = head;
    while (slow != fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}