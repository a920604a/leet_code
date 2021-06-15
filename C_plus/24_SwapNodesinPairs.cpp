/*
 * @Author: yuan
 * @Date: 2021-05-07 14:32:02
 * @LastEditTime: 2021-05-07 14:32:02
 * @FilePath: /C_plus/24_SwapNodesinPairs.cpp
 */
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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *cur = head;
        while (cur && cur->next)
        {
            int val = cur->val;
            cur->val = cur->next->val;
            cur->next->val = val;
            cur = cur->next->next;
        }

        return head;
    }
};