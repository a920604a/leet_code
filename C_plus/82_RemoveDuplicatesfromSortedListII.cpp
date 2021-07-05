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
        // option 1 O(nlogn) time O(s) space
        // 1. 儲存重複節點的值
        // 2. 建立一個新的list 比較是否重複節點，不是則加入新串列
        //         if(!head) return head;
        //         ListNode *ret = new ListNode(-101);
        //         set<int> s;
        //         ListNode *p = head;
        //         while(p->next){
        //             if(p->val ==p->next->val) s.insert(p->val);
        //             p=p->next;
        //         }
        //         p=ret;
        //         ListNode *cur = head;
        //         while(cur){
        //             if(s.find(cur->val)==s.end() ) {
        //                 p->next = new ListNode(cur->val);
        //                 p=p->next;

        //             }
        //             cur=cur->next;
        //         }
        //         return ret->next;

        // option 2 O(n^2) time O(1) space
        if (!head || !head->next)
            return head;
        ListNode *ret = new ListNode(-1), *p = ret;
        ret->next = head;
        while (p->next)
        {
            ListNode *run = p->next;
            while (run->next && run->next->val == run->val)
            {
                run = run->next;
            }
            if (run == p->next)
                p = p->next;
            else
                p->next = run->next;
        }
        return ret->next;
    }
};