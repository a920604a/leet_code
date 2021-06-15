/*
 * @Author: yuan
 * @Date: 2021-04-07 21:46:52
 * @LastEditTime: 2021-04-07 22:14:32
 * @FilePath: /C_plus/61_RotateList.cpp
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return head;
        ListNode *p1 = head;
        ListNode *p2 = head;
        int length = 1;
        while (p2->next)
        {
            p2 = p2->next;
            length++;
        }
        p2->next = head;
        for (int i = 0; i < length - k % length; ++i)
        {
            p1 = p1->next;
        }
        ListNode *ret = p1;
        for (int i = 0; i < length - 1; ++i)
        {
            p1 = p1->next;
        }
        p1->next = NULL;
        return ret;
    }
};