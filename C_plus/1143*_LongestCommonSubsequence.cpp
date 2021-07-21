class Solution
{
public:
    //     int dp(string s1, int i, string s2, int j ){
    //         // base case
    //         if(i== s1.size() || j==s2.size()) return 0;

    //         // s1[i] 、 s2[j] 都在最長子序列LCS
    //         if(s1[i] == s2[j]) return 1 + dp(s1,i+1, s2, j+1);
    //         else{

    //             // s1[i] 、 s2[j] 都不在LCS
    //             // s2[j] 都不在LCS
    //             // s1[i] 都不在LCS

    //             return max(
    //                     dp(s1, i+1, s2, j+1),
    //                         max(
    //                             dp(s1, i, s2, j+1),
    //                             dp(s1, i+1, s2, j)
    //                             )
    //                     );
    //         }
    //     }

    int dp(string s1, int i, string s2, int j, vector<vector<int> > &memo)
    {
        // base case
        if (i == s1.size() || j == s2.size())
            return 0;

        // 之前計算過
        if (memo[i][j] != -1)
            return memo[i][j];

        // s1[i] 、 s2[j] 都在最長子序列
        if (s1[i] == s2[j])
            return 1 + dp(s1, i + 1, s2, j + 1, memo);
        else
        {
            // s2[j] 都不在LCS
            // s1[i] 都不在LCS
            memo[i][j] = max(
                dp(s1, i, s2, j + 1, memo),
                dp(s1, i + 1, s2, j, memo));
        }
        return memo[i][j];
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        // option 1 brute force  time out

        // return dp(text1, 0, text2, 0);

        // option 2 memo pattern time out
        //         int n = text1.size(), m = text2.size();
        //         vector<vector<int>> memo(n , vector<int>(m,-1));

        //         return dp(text1, 0, text2, 0, memo);

        //         // option 3 use dp
        //         //    X a c e
        //         // X  0 0 0 0
        //         // a  0 1 1 1
        //         // b  0 1 1 1
        //         // c  0 1 2 2
        //         // d  0 1 2 2
        //         // e  0 1 2 3
        int n = text1.size(), m = text2.size();
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};