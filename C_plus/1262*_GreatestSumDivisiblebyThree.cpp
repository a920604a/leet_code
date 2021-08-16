class Solution
{
public:
    int maxSumDivThree(vector<int> &nums)
    {

        // 當下數字 選或 沒選 都更新 dp

        // dp
        //     0   1   2
        //     0   -   -
        //3    3.  -+3   -+3
        //6    9.  -+9   -+9
        //5    9   14   -+15
        //1    15  14  10
        //8    18  23  22

        int n = nums.size();
        vector<vector<int> > dp(n + 1, vector<int>(3, 0));
        dp[0][0] = 0;
        dp[0][1] = INT_MIN, dp[0][2] = INT_MIN;
        for (int i = 1; i <= n; ++i)
        {
            // 當下數字 選或 沒選 都更新 dp
            if (nums[i - 1] % 3 == 0)
            {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][0] + nums[i - 1]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][1] + nums[i - 1]);
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][2] + nums[i - 1]);
            }
            else if (nums[i - 1] % 3 == 1)
            {
                // 該數字 餘數為 1 ，餘2的數字 + 餘1的數字 相加會餘0
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] + nums[i - 1]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + nums[i - 1]);
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + nums[i - 1]);
            }
            else
            {
                // 該數字 餘數為 2 ，餘2的數字 + 餘1 的數字 相加會餘0
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + nums[i - 1]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] + nums[i - 1]);
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][0] + nums[i - 1]);
            }
        }
        return dp[n][0];
    }
};