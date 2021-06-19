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

        // option 1 copy the next node's value and delete it.
        node->val = node->next->val;
        ListNode *delnode = node->next;
        node->next = node->next->next;
        delete delnode;
    }
};