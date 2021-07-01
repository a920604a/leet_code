class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        // option 1 O(n^2) dp
        int n = nums.size(), ret = 0;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
            ret = max(ret, dp[i]);
        }
        return ret;

        // O(nlogn) binary search
    }
};