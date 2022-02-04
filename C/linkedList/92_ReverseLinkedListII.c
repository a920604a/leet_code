/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *reverseN(struct ListNode *head, int right)
{
    struct ListNode *pre = (struct ListNode *)malloc(sizeof(struct ListNode));
    pre->next = head;
    struct ListNode *cur = head;
    for (int i = 0; i < right; ++i)
    {
        struct ListNode *temp = cur->next;
        cur->next = temp->next;
        temp->next = pre->next;
        pre->next = temp;
    }
    return pre->next;
}

struct ListNode *reverseBetween(struct ListNode *head, int left, int right)
{
    if (!head || !head->next)
        return head;
    if (left == 1)
        return reverseN(head, right - 1);
    head->next = reverseBetween(head->next, left - 1, right - 1);
    return head;
}