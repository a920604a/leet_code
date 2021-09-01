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
    ListNode *insertionSortList(ListNode *head)
    {

        // option1
        // 因為串列特性，
        // 1. 新增一個串列，每次搜尋一個節點，
        // 2. 與串列從頭每個元素作比較，直到大於該元素，並插入
        // option 1 insert sort
        if (!head || !head->next)
            return head;
        ListNode *ret = head, *cur = head->next;
        ret->next = nullptr;
        while (cur)
        {
            ListNode *k = cur;
            cur = cur->next;
            ListNode *j = ret, *pre = ret;
            while (j && j->val < k->val)
            {
                pre = j;
                j = j->next;
            }
            if (j == ret)
            {
                // insert first;
                k->next = ret;
                ret = k;
            }
            else
            {
                pre->next = k;
                k->next = j;
            }
        }
        return ret;
    }
};