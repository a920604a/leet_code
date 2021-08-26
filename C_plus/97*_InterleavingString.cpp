class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {

        // option 1

        // s1 s2 長度總和必須為等於 s3長度，所以不等於返回false 。 s1 s2 為空，s3必為空字串
        //   空    d   b   b   c   a
        //空  t   f   f   f   f   f
        //a   t
        //a   t
        //b   f
        //c   f
        //c   f

        if (s1.size() + s2.size() != s3.size())
            return false;
        int n = s1.size(), m = s2.size();
        vector<vector<bool> > dp(n + 1, vector<bool>(m + 1, false));
        //base case
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i)
        {
            if (s1[i - 1] == s3[i - 1])
                dp[i][0] = dp[i - 1][0];
        }
        for (int j = 1; j <= m; ++j)
        {
            if (s2[j - 1] == s3[j - 1])
                dp[0][j] = dp[0][j - 1];
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i - 1 + j]) || (dp[i][j - 1] && s2[j - 1] == s3[j - 1 + i]);
            }
        }
        return dp[n][m];
        // option 2 O(s2.length) space
    }
};