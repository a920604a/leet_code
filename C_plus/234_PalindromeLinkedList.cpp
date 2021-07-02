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
    bool isPalindrome(ListNode *head)
    {
        // option 1  O(n) space O(n) time
        // 切半
        //         if(!head || !head->next) return true;
        //         stack<int> sta;

        //         // make use of stack property to determine
        //         ListNode *p = head;
        //         while(p){
        //             sta.push(p->val);
        //             p=p->next;
        //         }
        //         p =head;
        //         while(p){
        //             if(p->val != sta.top()) return false;
        //             sta.pop();
        //             p=p->next;
        //         }
        //         return true;

        // option 2

        // O(n) two pointer + reverse last half of linked list
        if (!head || !head->next)
            return true;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *last = slow->next, *p = head;
        // reverse half of linked list
        while (last->next)
        {
            ListNode *temp = last->next;
            last->next = temp->next;
            temp->next = slow->next;
            slow->next = temp;
        }

        while (slow->next)
        {
            slow = slow->next;
            if (p->val != slow->val)
                return false;
            p = p->next;
        }
        return true;

        // option 3 Recursion & backtracking
    }
};