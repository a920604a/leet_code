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
    ListNode *successor = nullptr;

public:
    ListNode *reverseN(ListNode *head, int n)
    {
        if (n == 1)
        {
            successor = head->next;
            return head;
        }
        ListNode *node = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = successor;
        return node;
    }
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        // if(!head) return head;
        // ListNode *pre = new ListNode(-1), *ret = pre;
        // pre->next = head;
        // for(int i=0;i<left-1;++i) pre = pre->next;
        // ListNode *cur = pre->next;
        // for(int i=left;i<right;++i){
        //     ListNode *temp = cur->next;
        //     cur->next = temp->next;
        //     temp->next = pre->next;
        //     pre->next = temp;
        // }
        // return ret->next;
        if (left == 1)
            return reverseN(head, right);

        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }
};