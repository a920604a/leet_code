class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {

        //          1   4   6   7   8   20
        //      inf inf inf inf inf inf inf
        //i=1   0   2   inf inf inf inf inf
        //i=2   0   2   4
        //i=3   0   2   4   6
        //i=4   0   2   4   6   7
        //i=5   0   2   4   6   7   9
        //i=6   0   2   4   6   7   9   11

        int d = days.size(), n = costs.size();
        vector<int> dp(d + 1, INT_MAX);
        // init dp
        dp[0] = 0;

        for (int i = 1; i <= d; ++i)
        {
            dp[i] = min(dp[i], dp[i - 1] + costs[0]);
            for (int j = 1; j <= i; j++)
            {
                if (days[i - 1] - days[j - 1] < 7)
                    dp[i] = min(dp[i], dp[j - 1] + costs[1]);
                if (days[i - 1] - days[j - 1] < 30)
                    dp[i] = min(dp[i], dp[j - 1] + costs[2]);
            }
        }
        return dp[d];
    }
};