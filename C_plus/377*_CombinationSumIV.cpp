class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {

        // dp [1,2,3] 4
        //  0   1   2   3   4
        //  1   1   2   4   7

        // [9] 3
        //  0   1   2   3
        //  1   0   0   0

        // avoid overflow
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i)
        {
            for (auto a : nums)
            {
                if (i >= a)
                    dp[i] += dp[i - a];
            }
        }
        return dp.back();
    }
};