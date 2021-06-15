/*
 * @Author: yuan
 * @Date: 2021-04-29 15:35:45
 * @LastEditTime: 2021-04-29 15:35:52
 * @FilePath: /C_plus/160_IntersectionOrTwoLinkedList.cpp
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *a = headA;
        ListNode *b = headB;
        while (a != b)
        {
            a = (!a) ? headB : a->next;
            b = (!b) ? headA : b->next;
        }
        return a;
    }
};