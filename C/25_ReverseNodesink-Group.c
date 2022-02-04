/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *reverse(struct ListNode *l, struct ListNode *r)
{
    struct ListNode *cur = l;
    struct ListNode *pre = NULL;
    while (cur != r)
    {
        struct ListNode *temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}

struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
    struct ListNode *a, *b;
    a = b = head;
    for (int i = 0; i < k; ++i)
    {
        if (b == NULL)
            return head;
        b = b->next;
    }
    struct ListNode *newhead = reverse(a, b);
    a->next = reverseKGroup(b, k);
    return newhead;
}