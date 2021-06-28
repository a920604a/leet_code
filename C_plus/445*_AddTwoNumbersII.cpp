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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // use stack
        stack<int> s1, s2;
        for (; l1; l1 = l1->next)
            s1.push(l1->val);
        for (; l2; l2 = l2->next)
            s2.push(l2->val);

        ListNode *ret = new ListNode(0), *p = ret;
        int carry = 0, sum;
        while (!s1.empty() || !s2.empty() || carry)
        {
            sum = carry;
            if (!s1.empty())
            {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty())
            {
                sum += s2.top();
                s2.pop();
            }

            p->next = new ListNode(sum % 10);
            p = p->next;
            carry = sum / 10;
        }
        // reverse link list
        ListNode *pre = nullptr, *cur = ret->next, *post = ret->next->next;
        while (post)
        {
            cur->next = pre;
            pre = cur;
            cur = post;
            post = post->next;
        }
        cur->next = pre;
        ret = cur;
        return ret;
    }
};