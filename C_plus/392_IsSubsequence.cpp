class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if (s.empty())
            return true;
        int n = s.size(), m = t.size();
        if (n > m)
            return false;
        vector<vector<int> > dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = s[0] == t[0] ? 1 : 0;
                else if (i == 0)
                {
                    if (s[i] == t[j])
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i][j - 1];
                }
                else if (j == 0)
                {
                    if (s[i] == t[j])
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    if (s[i] == t[j])
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    else
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return dp[n - 1][m - 1] == n;
    }
};