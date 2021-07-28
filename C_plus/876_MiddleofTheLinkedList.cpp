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
    ListNode *middleNode(ListNode *head)
    {
        // option 1 O(n)
        // get list size
        // int size = 0;
        // ListNode *p = head;
        // while(p){
        //     size++;
        //     p=p->next;
        // }
        // p=head;
        // size /=2;
        // while(size){
        //     size--;
        //     p=p->next;
        // }
        // return p;

        // option 2 O(n) slow fast point
        ListNode *slow =head, *fast=head;
        while(fast && fast->next){
            slow = slow->next;
            fast= fast->next->next;
        }
        return slow;

        // option 3 use STL
        vector<ListNode *> ret(100);
        int cur = 0;
        while (head)
        {
            ret[cur++] = head;
            head = head->next;
        }
        return ret[cur / 2];
    }
};