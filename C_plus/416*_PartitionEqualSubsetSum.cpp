class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        // 維護一個dp，表示數組是否能取出若干個數，其和為i
        int sum = accumulate(nums.begin(), nums.end(), 0), target = sum >> 1;
        if (sum & 1)
            return false;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num : nums)
        {
            for (int i = target; i >= num; i--)
            {
                dp[i] = dp[i] || dp[i - num];
            }
        }

        return dp[target];
    }
};