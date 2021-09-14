/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{

    struct ListNode *slow = malloc(sizeof(struct ListNode)), *fast = slow, *ret = slow;
    slow->next = head;
    while (n--)
    {
        fast = fast->next;
    }
    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return ret->next;
}