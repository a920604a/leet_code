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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // option 1  O(n) time
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
        
        // option 2 two pointer
        ListNode *p1 = new ListNode(0), *ret = p1;
        ListNode *p2 = new ListNode(0) ,*t=p2;
        ListNode *p = head;
        for(;p;p=p->next){
            if(p->val<x){
                p1->next = new ListNode(p->val);
                p1=p1->next;
            }
            else{
                p2->next = new ListNode(p->val);
                p2=p2->next;
            }
        }
        p1->next = t->next;
        return ret->next;
        
    }
};