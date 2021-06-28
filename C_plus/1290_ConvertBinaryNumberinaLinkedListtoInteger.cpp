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
    int getDecimalValue(ListNode *head)
    {
        // option 1 O(N) time, O(1) space
        int ret = 0;
        for (ListNode *p = head; p; p = p->next)
        {
            ret <<= 1;
            ret += (p->val);
        }
        return ret;
    }
};