// option 2 O(n^2) time O(1) space
ListNode *p = head;

while (p)
{
    ListNode *run = p;
    while (run->next)
    {
        if (run->next->val == p->val)
            run->next = run->next->next;
        else
            run = run->next;
    }
    p = p->next;
}

return head;