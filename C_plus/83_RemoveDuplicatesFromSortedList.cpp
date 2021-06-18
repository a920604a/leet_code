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
    ListNode *deleteDuplicates(ListNode *head)
    {

        // option 1 delete node
        ListNode *dummy = new ListNode(-101), *pre = dummy;
        dummy->next = head;

        if (head == nullptr || head->next == nullptr)
            return head;

        while (dummy->next)
        {
            if (dummy->val == dummy->next->val)
            {
                ListNode *delnode = dummy->next;
                dummy->next = dummy->next->next;
                delete delnode;
            }
            else
                dummy = dummy->next;
        }
        return pre->next;
    }
};