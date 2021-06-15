/*
 * @Author: yuan
 * @Date: 2021-05-01 19:33:33
 * @LastEditTime: 2021-05-01 19:33:43
 * @FilePath: /C_plus/237_DeleteNodeInaLinkedList.cpp
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
    void deleteNode(ListNode *node)
    {
        ListNode *p = node->next;
        node->val = p->val;
        node->next = p->next;
        delete p;
    }
};