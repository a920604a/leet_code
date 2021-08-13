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

        int n = days.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + costs[0];

            for (int j = 1; j <= i; ++j)
            {
                // cout<<i<<" "<<j<<endl;
                // 如果 [i] - [j] 差距小於7天，可以用 j-1天的錢 加上 [j...i] 買一張 七天票即可
                if (days[i - 1] - days[j - 1] < 7)
                    dp[i] = min(dp[i], dp[j - 1] + costs[1]);
                if (days[i - 1] - days[j - 1] < 30)
                    dp[i] = min(dp[i], dp[j - 1] + costs[2]);
            }
            // for(int d:dp) cout<<d<<" ";
            // cout<<endl;
        }
        return dp[n];
    }
};