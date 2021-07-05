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
        if (!head || !head->next)
            return head;
        ListNode *ret = new ListNode(-5001), *p = head;
        ListNode *cur = ret;
        while (p)
        {
            ListNode *last = p->next; // 記住下次要處理的節點
            while (cur->next && cur->next->val <= p->val)
                cur = cur->next;
            // insert node
            p->next = cur->next;
            cur->next = p;
            // 歸位
            p = last;
            cur = ret;
        }
        return ret->next;
    }
};