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
    ListNode *partition(ListNode *head, int x)
    {
        // option 1 O(N) time and O(N) space
        // 1. 分別照順序收集小於x，大於等於x的
        // 2. 將兩個queue串起來
        //         if(!head) return head;
        //         queue<int> q, q2;
        //         ListNode *p= head;
        //         ListNode *ret = new ListNode(-201);
        //         while(p){
        //             if(p->val<x) q.push(p->val);
        //             else q2.push(p->val);
        //             p=p->next;
        //         }

        //         p=ret;
        //         while(!q.empty()){
        //             int k = q.front();
        //             ListNode *t = new ListNode(k);
        //             q.pop();
        //             if(t) p->next = t;
        //             p=p->next;
        //         }
        //         while(!q2.empty()){

        //             int k = q2.front();
        //             cout<<k<<endl;
        //             q2.pop();
        //             p->next = new ListNode(k);
        //             p=p->next;
        //         }
        //         return ret->next;

        // option 2 O(N) time and O(1) space two pointer
        // 1. 分別new 兩個起始節點，稍後travese linked list 判斷該節點大於等於還是小於，已分別放入不同串列
        // 2. 將兩個串列串起來
        ListNode *p1 = new ListNode(0), *ret = p1;
        ListNode *p2 = new ListNode(0), *t = p2;
        ListNode *p = head;
        for (; p; p = p->next)
        {
            if (p->val < x)
            {
                p1->next = new ListNode(p->val);
                p1 = p1->next;
            }
            else
            {
                p2->next = new ListNode(p->val);
                p2 = p2->next;
            }
        }
        p1->next = t->next;
        return ret->next;
    }
};