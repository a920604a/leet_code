class Solution
{
public:
    int minInsertions(string s)
    {

        /*
        if (s[i] == s[j]) {
            dp[i][j] = dp[i + 1][j - 1];
        }
        else if(s[i] != s[j]){
            // 把 s[j] 插到 s[i] 右邊，同時把 s[i] 插到 s[j] 右邊
            dp[i][j] = dp[i + 1][j - 1] + 2;
            
            做選擇，先將 s[i..j-1] 或者 s[i+1..j] 變成回文串
            dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
        }
        */
        int n = s.size();
        vector<vector<int> > dp(n, vector<int>(n, 0));
        // initalize dp
        for (int i = 0; i < n; ++i)
            dp[i][i] = 0;

        for (int i = n - 1; i > -1; --i)
        {
            for (int j = i + 1; j < n; ++j)
            {

                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1];
                else if (s[i] != s[j])
                {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                }
            }
        }

        return dp[0][n - 1];
    }
};