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
    ListNode *sortList(ListNode *head)
    {
        // option 1 beacause of return , so can use STL story each node and generate linked list
        // if(!head || !head->next) return head;
        // vector<int> v;
        // ListNode *p = head;
        // while(p){
        //     v.emplace_back(p->val);
        //     p=p->next;
        // }
        // sort(v.begin(), v.end());
        // ListNode *ret = new ListNode(v[0]);
        // p =ret;
        // for(int i=1;i<v.size();++i,p = p->next){
        //     p->next = new ListNode(v[i]);
        // }
        // return ret;

        // option 2 O(nlogn) , so quick sort or quick sort
        // merge sort
        // 1. split each node using slow fast point
        // 2. merge strategy
        if (!head || !head->next)
            return head;
        ListNode *slow = head, *fast = head, *pre = head;
        while (fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;

        return merge(sortList(head), sortList(slow));
    }
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode *cur = new ListNode(0), *ret = cur;

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }
        if (l1)
            cur->next = l1;
        if (l2)
            cur->next = l2;

        return ret->next;
    }
};