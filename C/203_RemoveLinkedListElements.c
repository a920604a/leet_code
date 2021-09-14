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
    struct ListNode *slow = malloc(sizeof(struct ListNode)), *fast = head, *ans = slow;
    slow->next = head;
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
    return ans->next;
}