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
    ListNode *detectCycle(ListNode *head)
    {

        // option 1
        // 1. 快慢指標判斷有無交點
        // 2. 若無交點，返回nullptr
        // 3. 有交點，此時fast從相遇點走到下次相遇點距離，等於slow從起點走到下次相遇點。
        ListNode *slow = head, *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
                break; // detect cycle
        }
        // fast遇到空指標，代表沒有環
        if (fast == nullptr || fast->next == nullptr)
            return nullptr;

        slow = head;
        while (slow != fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};