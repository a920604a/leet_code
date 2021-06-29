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
    int numComponents(ListNode *head, vector<int> &nums)
    {
        unordered_set<int> nodeset(nums.begin(), nums.end());
        int ret = 0;
        while (head)
        {
            if (!nodeset.count(head->val))
            { // not find head node in the nodeset
                head = head->next;
                continue;
            }
            else
            {
                while (head && nodeset.count(head->val))
                { // find head node in the nodeset
                    head = head->next;
                }
                ret++;
            }
        }
        return ret;
    }
};