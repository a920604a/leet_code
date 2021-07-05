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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // option 1
        // 1. use stack to store each node
        // 2. 按照stack pop順序相加節點至串列
        // 3. reverse linked list
        // use stack
        //         stack<int> s1,s2;
        //         for(;l1;l1=l1->next) s1.push(l1->val);
        //         for(;l2;l2=l2->next) s2.push(l2->val);

        //         ListNode *ret = new ListNode(0),*p=ret;
        //         int carry=0, sum;
        //         while( !s1.empty() || !s2.empty() || carry){
        //             sum = carry;
        //             if(!s1.empty()){
        //                 sum += s1.top();
        //                 s1.pop();
        //             }
        //             if(!s2.empty()){
        //                 sum+= s2.top();
        //                 s2.pop();
        //             }

        //             p->next = new ListNode(sum%10);
        //             p=p->next;
        //             carry = sum/10;
        //         }
        //         // reverse link list
        //         ListNode *pre =nullptr, *cur = ret->next, *post = ret->next->next;
        //         while(post){
        //             cur->next =pre;
        //             pre = cur;
        //             cur=post;
        //             post=post->next;
        //         }
        //         cur->next = pre;
        //         ret = cur;
        //         return ret;

        // option 2 use recursive insted of stack
        // 1. 先取得各串列長度
        // 2. 對齊
        // 3. 相加
        int len1 = getListLen(l1);
        int len2 = getListLen(l2);

        if (len1 >= len2)
            return addSecondToFirst(l1, l2, len1, len2);
        return addSecondToFirst(l2, l1, len2, len1);
    }
    int getListLen(ListNode *l)
    {
        int res = 0;
        while (l)
        {
            res++;
            l = l->next;
        }
        return res;
    }
    ListNode *addSecondToFirst(ListNode *l1, ListNode *l2, int len1, int len2)
    {
        ListNode *ret = l1;
        while (len1 > len2)
        {
            l1 = l1->next;
            len1--;
        }
        int carry = addSameWidth(l1, l2);

        carry = addCarryToList(ret, carry, l1);

        if (carry != 0)
        {
            ret = new ListNode(carry, ret);
        }
        return ret;
    }
    int addCarryToList(ListNode *res, int num, ListNode *l1)
    {
        if (res == l1)
            return num;
        int carry = addCarryToList(res->next, num, l1);
        int sum = carry + res->val;
        res->val = sum % 10;
        return sum / 10;
    }
    int addSameWidth(ListNode *l1, ListNode *l2)
    {

        if (!l1)
            return 0;
        int carry = addSameWidth(l1->next, l2->next);
        int sum = l1->val + l2->val + carry;
        l1->val = sum % 10;
        return sum / 10;
    }
};