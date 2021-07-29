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
        // option 1 O(N) time , O(1) space  直接修改節點的值 without extra space

        if (!head)
            return head;

        ListNode *slow, *fast;
        slow = fast = head;
        while (fast)
        {

            if (fast->val != slow->val)
            {

                // nums[slow] = nums[fast]
                slow->next = fast;
                // slow++;
                slow = slow->next;
            }
            fast = fast->next;
        }
        // 斷開後面重複元素的連接
        slow->next = nullptr;
        return head;

        // option 1.1 只用單指標處理
        // if(!head) return head;
        // ListNode *p = head;
        // while(p->next){
        //     if(p->next->val==p->val) p->next = p->next->next;
        //     else p=p->next;
        // }
        // return head;

        // option 2 O(n^2) time O(1) space brute force
        //         ListNode *p = head;

        //         while(p){
        //             ListNode *run = p;
        //             while(run->next){
        //                 if(run->next->val==p->val)  run->next = run->next->next;
        //                 else run =run->next;
        //             }
        //             p=p->next;
        //         }

        //         return head;

        // option 3 O(N) time O(s) space 不能修改節點，用set儲存出現過的值
        // set 容器裡面是會幫你排序的，因為set 是紅黑樹實作的，二元搜尋樹
        // set<int> s;
        // for(ListNode *p=head;p;p=p->next){
        //     s.insert(p->val);
        // }
        // ListNode *ret = new ListNode(-1), *p=ret;
        // for(auto iter = s.begin();iter!=s.end();++iter){
        //     p->next = new ListNode(*iter);
        //     p = p->next;
        // }
        // return ret->next;
    }
};