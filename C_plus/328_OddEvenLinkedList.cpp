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
        // option 1
        // two pointer , pointer odd, even
        // if(!head || !head->next) return head;
        // ListNode* odd =head, *even = head->next;
        // ListNode *p = even;
        // while(odd->next && even->next){
        //     odd->next = even->next;
        //     even->next = even->next->next;
        //     odd=odd->next;
        //     even=even->next;
        // }
        // odd->next = p;
        // return head;

        // option 2
        if (!head || !head->next)
            return head;
        ListNode *pre = head, *cur = head->next;
        while (cur && cur->next)
        {
            ListNode *tmp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = tmp;
            pre = pre->next;
            cur = cur->next;
        }

        return head;
    }
};