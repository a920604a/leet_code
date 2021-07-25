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
private:
    ListNode *left;
public:
    bool isPalindrome(ListNode *head)
    {
        // option 1 stack O(n) time and O(n) space
        // 1. 前半部push到stack，後半部pop stack並比較其值是否相同，
        // 2. 整條list push 到stack，在比較也可以
        // if(!head || !head->next) return true;
        // stack <int> sta;
        // int len = 0;
        // for(ListNode *p=head;p;p=p->next) len++;
        // int half = len/2;
        // ListNode *p=head;
        // while(half){
        //     sta.push(p->val);
        //     p=p->next;
        //     half--;
        // }
        // if(len%2==1) p=p->next;
        // while(p && !sta.empty()){
        //     if(sta.top()!=p->val) return false;
        //     sta.pop();
        //     p=p->next;
        // }
        // return true;

        // option 2 slow-fast 適合用在未知大小串列 O(n) time and O(1) space
        // 1. 快慢指針決定中點
        // 2. 中點後的串列reverse 或是靠stack
        // 3. 用兩指針，一個指向頭、另一個指向中點，遍歷並比較是否相同
        // if(!head || !head->next) return true;
        //         ListNode *slow  = head, *fast = head;
        //         while(fast->next && fast->next->next){
        //             slow = slow->next;
        //             fast = fast->next->next;
        //         }
                
        //         ListNode *cur = slow, *post = slow->next, *pre = nullptr;
                
        //         while(post){
        //             cur->next = pre;
        //             pre = cur;
        //             cur = post;
        //             post = post->next;
        //         }
        //         cur->next = pre;
                
        //         slow = cur;
        //         cur = head;
        //         while(slow->next){
        //             if(cur->val != slow->val) return false;
        //             cur=cur->next;
        //             slow = slow->next;           
        //         }
        //         return true;

        // option 3.2 slow-fast 適合用在未知大小串列 O(n) time and O(1) space
        // if(!head || !head->next) return true;
        // ListNode *slow = head , *fast = head, *pre;
        // stack<int> sta;
        // while(fast && fast->next){
        //     sta.push(slow->val);
        //     slow =slow->next;
        //     fast = fast->next->next;
        // }
        // if(fast!=nullptr)  slow = slow->next;
        // while(slow){
        //     if(sta.top() !=slow->val) return false;
        //     sta.pop();
        //     slow=slow->next;
        // }
        // return true;

        // option 4 reverse and compare O(n) time and O(n) space
        // 1. new 一個reverse的串列  ，不斷的insert 串列的頭
        // 2. 比較兩者是否相同
        // ListNode *mirror = nullptr;
        // for(ListNode *p=head;p;p=p->next){
        //     ListNode *tmp = new ListNode(p->val);
        //     tmp->next = mirror;
        //     mirror = tmp;
        // }
        // for(ListNode *p=head, *q = mirror;p, q;p=p->next, q=q->next){
        //     if(p->val !=q->val) return false;
        // }
        // return true;

        // option 5 recursive O(n) time and O(n) space
        left = head;
        return travese(head->next);
    }

    bool travese(ListNode *right){
        if(right==nullptr) return true;
        
        bool ret = travese(right->next);
        ret = ret && (right->val == left->val);
        left = left->next;
        return ret;
    }
};