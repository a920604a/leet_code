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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        ListNode *p = head;
        int len = 1;
        // 串列長度
        while (p->next)
        {
            p = p->next;
            len++;
        }
        p->next = head; // 串列變成cycle
        cout << "length of list: " << len << endl;

        ListNode *start = head;
        // 決定起點
        int n = len - k % len;
        while (n)
        {
            start = start->next;
            n--;
        }
        cout << "start's value: " << start->val << endl;
        ListNode *res = start;
        //決定終點
        len--;
        while (len)
        {
            start = start->next;
            len--;
        }
        start->next = nullptr;

        return res;
    }
};