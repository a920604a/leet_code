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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {

        ListNode *ret = new ListNode(0), *p = ret;

        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }

        if (l1)
        {
            p->next = l1;
        }
        if (l2)
        {
            p->next = l2;
        }

        return ret->next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        //option 1
        // if(lists.empty()) return nullptr;
        // ListNode *ret = lists[0];
        // for(int i =1;i<lists.size();++i){
        //     ret = mergeTwoLists(ret, lists[i]);
        // }
        // return ret;

        // option 2 divide and conquer
        if (lists.empty())
            return nullptr;
        int n = lists.size();
        while (n > 1)
        {
            int k = (n + 1) / 2;
            for (int i = 0; i < n / 2; i++)
            {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            n = k;
        }
        return lists[0];
    }
};