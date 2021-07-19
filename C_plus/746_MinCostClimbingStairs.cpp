class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        // 10 15 20  => 10 10 10 15=min(10+20,15)
        // 1 100 1 1 1 100 1 1 100 1
        // 0  0  1 2 3  3  3 4   4 5 6

        int size = cost.size();
        if (size < 3)
            min(cost[0], cost[1]);
        vector<int> dp(size + 1, 999);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= size; ++i)
        {
            dp[i] = min(cost[i - 1] + dp[i - 1], cost[i - 2] + dp[i - 2]);
        }
        return dp[size];
    }
};