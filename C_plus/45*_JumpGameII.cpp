class Solution
{
public:
    int jump(vector<int> &nums)
    {
        // 2 3 1 1 4
        // 0 1 1 2 2

        // 2 3 0 1 4
        // 0 1 1 2 2
        int n = nums.size();
        vector<int> dp(n, n + 1);
        dp[0] = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j <= i + nums[i] && j < n; ++j)
            {
                dp[j] = min(dp[i] + 1, dp[j]);
            }
        }
        return dp[n - 1];
    }
};