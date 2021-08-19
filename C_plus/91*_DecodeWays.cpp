class Solution
{
public:
    int numDecodings(string s)
    {

        //dp
        //      2   2   6
        //  0   0   0   0
        //  1   1   2   3
        //  只要不為零，初始值都為dp[i-1]
        //  22 => B B(2 2) or V(22)
        //  26 => B B F(2 2 6) V F(22 6) B Z (2 26)
        if (s.empty() || s[0] == '0')
            return 0;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            if (s[i - 1] != '0')
                dp[i] = dp[i - 1];

            if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')))
            {
                dp[i] += dp[i - 2];
            }
        }
        return dp.back();
    }
};