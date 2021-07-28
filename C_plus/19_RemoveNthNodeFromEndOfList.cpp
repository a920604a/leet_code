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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // option 1  two pointer 不知道串列長度 iterative
        // ListNode *fast = new ListNode(0), *slow = fast, *ret = slow;
        // fast->next = head;
        // while (n)
        // {
        //     fast = fast->next;
        //     n--;
        // }

        // while (fast->next)
        // {
        //     slow = slow->next;
        //     fast = fast->next;
        // }

        // slow->next = slow->next->next;
        // return ret->next;

        // option 1.1 不額外使用space
        // ListNode *slow , *fast ;
        // slow = fast = head;

        // // 會先做 n>0 再 n--
        // while(n-- >0) fast = fast->next;

        // // 表示刪除鏈接串列的頭
        // if(fast == nullptr) return head->next;

        // while(fast && fast->next){
        //     slow = slow->next;
        //     fast = fast->next;
        // }

        // slow->next = slow->next->next;

        // return head;

        // option 2 Recursive
        int curr = -1;
        return helper(head, n, curr);
    }
    ListNode *helper(ListNode *node, int &n, int &curr)
    {
        if (!node)
        {
            curr = 0;
            return NULL;
        }
        node->next = helper(node->next, n, curr);
        if (++curr == n)
        {
            return node->next;
        }
        return node;
    }
};