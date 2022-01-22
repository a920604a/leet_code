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
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {

        // O(n) time
        int local_min = INT_MAX, local_max = INT_MIN;

        vector<int> ret(2, -1);
        if (!head || !head->next || !head->next->next)
            return ret;
        ListNode *pre = head, *cur = head->next, *post = head->next->next;
        // vector<pair<ListNode*, int>> collect;
        vector<int> nums;
        int i = 1;
        while (post)
        {
            if (cur->val > pre->val && cur->val > post->val)
            {
                local_max = max(local_max, cur->val);
                // collect.push_back(make_pair(cur, i));
                nums.push_back(i);
            }
            else if (cur->val < pre->val && cur->val < post->val)
            {
                local_min = min(local_min, cur->val);
                // collect.push_back(make_pair(cur, i));
                nums.push_back(i);
            }

            i++;
            pre = cur;
            cur = post;
            post = post->next;
        }

        if (nums.empty() || nums.size() == 1)
            return {-1, -1};
        for (int n : nums)
            cout << n << " ";
        // given increase arr , to find max diff and min diff
        //  2   4   5 => 1,3
        //  1   4   =>  3,3
        //
        int minDistance = INT_MAX, maxDistance = INT_MIN;
        maxDistance = nums.back() - nums.front();
        for (int i = 1; i < nums.size(); ++i)
        {
            minDistance = min(minDistance, nums[i] - nums[i - 1]);
        }

        return {minDistance, maxDistance};
    }
};