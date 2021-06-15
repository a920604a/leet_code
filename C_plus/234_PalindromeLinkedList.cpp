/*
 * @Author: yuan
 * @Date: 2021-05-01 19:25:42
 * @LastEditTime: 2021-05-01 19:25:42
 * @FilePath: /C_plus/234_PalindromeLinkedList.cpp
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
    bool isPalindrome(ListNode *head)
    {
        stack<int> s;
        ListNode *p = head;
        if (!head || !head->next)
            return true;
        while (p)
        {
            s.push(p->val);
            p = p->next;
        }
        while (head)
        {
            if (head->val != s.top())
                return false;
            s.pop();
            head = head->next;
        }
        return true;
    }
};