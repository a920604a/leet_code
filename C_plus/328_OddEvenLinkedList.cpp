/*
 * @Author: yuan
 * @Date: 2021-05-02 12:15:16
 * @LastEditTime: 2021-05-02 12:15:16
 * @FilePath: /C_plus/328_OddEvenLinkedList.cpp
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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *e = even;

        while (even && even->next)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = e;

        return head;
    }
};