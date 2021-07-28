/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        // two pointer ，slow fast point 用於linked list是否包含環, left right pointer用於數組 二元搜尋法
        // option 1  two pointer , slow fast
        ListNode *slow, *fast = head;
        while (fast && fast->next)
        {

            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;

        // option 2
        // set<ListNode*> s;

        // for(ListNode *cur = head;cur;cur=cur->next){
        //     if(s.find(cur)!= s.end()) return true;

        //     s.insert(cur);
        // }

        // return false;
    }
};