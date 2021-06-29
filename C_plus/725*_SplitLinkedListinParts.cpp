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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> ret(k, nullptr);
        int len = 0;
        for (ListNode *p = head; p; p = p->next)
            len++;
        int r = len % k, p = len / k;

        ListNode *node = head, *prev = nullptr;
        for (int i = 0; node && i < k; i++, r--)
        {
            ret[i] = node;
            for (int j = 0; j < p + (r > 0); j++)
            {
                prev = node;
                node = node->next;
            }
            prev->next = nullptr;
        }
        return ret;
    }
};