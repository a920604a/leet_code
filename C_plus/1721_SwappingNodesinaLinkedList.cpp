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
    ListNode *swapNodes(ListNode *head, int k)
    {
        // option 1 overwrite each other value
        int len = 0;
        for (ListNode *p = head; p; p = p->next)
            len++;
        // swap two node by index k , and len-k+1
        int n1 = k, n2 = len - k + 1;
        ListNode *node1 = head, *node2 = head;
        n1--;
        while (n1)
        {
            node1 = node1->next;
            n1--;
        }
        n2--;
        while (n2)
        {
            node2 = node2->next;
            n2--;
        }
        // swap
        swap(node1->val, node2->val);
        // int tmp = node1->val ;
        // node1->val = node2->val;
        // node2->val = tmp;
        return head;
    }
};