/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        //
        if (head == nullptr)
            return head;
        ListNode *dummy = new ListNode(-1), *p = dummy;
        p->next = head;

        while (p->next)
        {
            if (p->next->val == val)
            {
                p->next = p->next->next;
            }
            else
                p = p->next;
        }
        return dummy->next;

        // slow fast pointer
        ListNode *ret = new ListNode(-1);
        ret->next = head;
        ListNode *slow = ret, *fast = head;

        while (fast)
        {
            if (fast->val == val)
            {
                slow->next = fast->next;
            }
            else
                slow = slow->next;
            fast = fast->next;
        }
        return ret->next;
    }
};