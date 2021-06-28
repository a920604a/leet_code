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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        // option 1 vreate new linked list
        //         ListNode *ret = new ListNode(0), *p=ret;
        //         ListNode *cur = list1;
        //         while(a){
        //             p->next = new ListNode(cur->val);
        //             p=p->next;
        //             cur=cur->next;
        //             a--;
        //         }
        //         cur =list2;
        //         while(cur){
        //             p->next = new ListNode(cur->val);
        //             p=p->next;
        //             cur=cur->next;
        //         }

        //         cur=list1;
        //         while(b){
        //             cur=cur->next;
        //             b--;
        //         }
        //         cur=cur->next;
        //         while(cur){
        //             p->next = new ListNode(cur->val);
        //             p=p->next;
        //             cur=cur->next;
        //         }
        //         return ret->next;
        // option 2 in-place modify with two pointer
        ListNode *la = list1, *lb = la;
        for (int i = 0; i < a - 1; ++i)
            la = la->next;
        for (int i = 0; i <= b; ++i)
            lb = lb->next;
        la->next = list2;
        while (list2->next)
            list2 = list2->next;
        list2->next = lb;
        return list1;
    }
};