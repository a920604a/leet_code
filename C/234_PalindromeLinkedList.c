/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *left;
bool traverse(struct ListNode *right)
{
    if (right == NULL)
        return true;
    bool ret = traverse(right->next);
    if (right->val != left->val)
        return false;
    left = left->next;
    return ret;
}
bool isPalindrome(struct ListNode *head)
{
    // left = head;
    // return traverse(head->next);

    if (!head || !head->next)
        return true;
    struct ListNode *slow, *fast;
    slow = fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow = slow->next;
    struct ListNode *cur = slow, *pre = NULL, *post = slow->next;
    while (post)
    {
        cur->next = pre;
        pre = cur;
        cur = post;
        post = post->next;
    }

    cur->next = pre;

    slow = cur;
    cur = head;

    while (slow->next)
    {
        if (cur->val != slow->val)
            return false;
        cur = cur->next;
        slow = slow->next;
    }
    return true;
}