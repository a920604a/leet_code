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
        // option 1 O(nlogn)use STL
        // if (!head || !head->next) return head;
        // set<int> s;
        // ListNode *p=head;
        // while(p->next){
        //     if(p->val==p->next->val){
        //         s.insert(p->val);
        //     }
        //     p=p->next;
        // }
        // ListNode *ret = new ListNode(-101);
        // ret->next  = head;
        // p=ret;
        // while(p->next){
        //     if(s.find(p->next->val)!=s.end()){ //delete node
        //         ListNode * delnode = p->next;
        //         p->next = p->next->next;
        //         delete delnode;
        //     }
        //     else p=p->next;
        // }
        // return ret->next;

        // option 2
        if (!head || !head->next)
            return head;
        ListNode *ret = new ListNode(-101), *p = ret;
        ret->next = head;
        while (p->next)
        {
            ListNode *cur = p->next;
            while (cur->next && cur->next->val == cur->val)
            {
                cur = cur->next;
            }
            if (cur != p->next)
                p->next = cur->next;
            else
                p = p->next;
        }
        return ret->next;
    }
};