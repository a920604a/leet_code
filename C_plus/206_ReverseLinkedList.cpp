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
    ListNode *reverseList(ListNode *head)
    {
        // option 1 iterative

        //         if(!head || !head->next) return head;
        //         ListNode *pre = nullptr, *cur = head, *post = head->next;
        //         while(post){
        //             // 實施反轉
        //             cur->next = pre;
        //             // 置位
        //             pre = cur;
        //             cur = post;
        //             post = post->next;
        //         }

        //         cur->next = pre;
        //         head = cur;
        //         return head;

        // option 1 version 2

        // if(!head || !head->next) return head;
        // ListNode *pre = new ListNode(-1), *cur = head;
        // pre->next = cur;
        // ListNode * temp ;
        // while(cur->next){
        //     temp = cur->next;
        //     // 下次temp的位置先儲存起來
        //     cur->next = temp->next;
        //     // 實施反轉
        //     temp->next = pre->next;
        //     // 確保pre的next為反轉後的頭head
        //     pre->next = temp;
        // }
        // head = temp;
        // return head;

        // option 2 recursive
        // 防止輸入為空鏈接串列
        if (head == nullptr)
            return head;
        if (head->next == nullptr)
            return head;
        ListNode *node = reverseList(head->next);
        // 利用call function 天然的stack性質
        head->next->next = head;
        head->next = nullptr;
        return node;
    }
};