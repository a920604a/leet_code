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

        // option 1  two pointer , slow fast
        if (!head)
            return head;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next)
        {

            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
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