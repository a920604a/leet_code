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
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        // option 1
        // Time O(N), one pass
        // SpaceO(N), for hashmap
        //         ListNode *ret = new ListNode(0), *p=ret;
        //         p->next = head;
        //         int prefix = 0;
        //         unordered_map<int, ListNode*> m;
        //         for(ListNode *i = ret;i;i=i->next){
        //             prefix +=i->val;
        //             if(m.find(prefix)!=m.end()){
        //                 ListNode *cur = m[prefix]->next;
        //                 ListNode *start = cur;
        //                 int aux = prefix + cur->val;

        //                 while(cur!=i){
        //                     m.erase(aux);
        //                     cur=cur->next;
        //                     aux += cur->val;

        //                 }
        //                 m[prefix]->next = cur->next;

        //             }
        //             else m[prefix] =i;

        //         }
        //         return ret->next;

        // option 2
        // Time O(N), two pass
        // SpaceO(N), for hashmap
        ListNode *ret = new ListNode(0);
        ret->next = head;
        unordered_map<int, ListNode *> m;
        int prefix = 0;
        for (ListNode *i = ret; i; i = i->next)
        {
            m[prefix += i->val] = i;
        }
        prefix = 0;
        for (ListNode *i = ret; i; i = i->next)
        {
            // prefix = i->val;
            i->next = m[prefix += i->val]->next;
        }
        return ret->next;
    }
};