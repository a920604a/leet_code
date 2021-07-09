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
    ListNode *reverseList(ListNode *head)
    {
        // option 1
        //         if(!head || !head->next) return head;

        //         ListNode *pre = nullptr;
        //         ListNode *cur = head;
        //         ListNode *post = head->next;
        //         while(post){
        //             cur->next =pre;
        //             pre = cur;
        //             cur=post;
        //             post=post->next;
        //         }
        //         cur->next = pre;
        //         head = cur;
        //         return head;

        // option 2
        if (!head || !head->next)
            return head;
        ListNode *pre = new ListNode(-1), *p = head;
        pre->next = head;
        ListNode *temp;
        while (p->next)
        {
            temp = p->next;
            p->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        head = temp;
        return head;


        // option 3 recursive

        if(head==nullptr || head->next==nullptr ) return head;
        ListNode* node = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return node;
    }
};