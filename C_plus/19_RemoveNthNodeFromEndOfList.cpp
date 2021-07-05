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
        //         ListNode *first = new ListNode(-1);
        //         ListNode *second = new ListNode(-1);
        //         first->next = head;
        //         second->next = head;
        //         int m=n;
        //         while(m){
        //             second = second->next;
        //             m--;
        //         }

        //         if(second->next==nullptr){ // remove head
        //             ListNode * delnode = first->next;
        //             head = first->next->next;
        //             return head;
        //         }
        //         while(second->next){
        //             first = first->next;
        //             second= second->next;
        //         }
        //         ListNode *delnode = first->next;
        //         first->next = first->next->next;
        //         delete delnode;
        //         return head;

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