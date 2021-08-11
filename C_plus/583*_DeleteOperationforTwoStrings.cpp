class Solution
{
public:
    map<tuple<int, int>, int> memo;
    int distance(string s1, string s2, int i, int j)
    {
        if (i == -1)
            return j + 1;
        if (j == -1)
            return i + 1;

        if (memo.count(make_pair(i, j)))
            return memo[make_pair(i, j)];

        if (s1[i] == s2[j])
            memo[make_pair(i, j)] = distance(s1, s2, i - 1, j - 1);
        else
            memo[make_pair(i, j)] = min(
                distance(s1, s2, i - 1, j) + 1,
                distance(s1, s2, i, j - 1) + 1);
        return memo[make_pair(i, j)];
    }
    //1143. Longest Common Subsequence
    int longestCommonSubsequence(string text1, string text2)
    {
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
    int minDistance(string word1, string word2)
    {
        // come from leetcode  72. Edit Distance
        // option 1
        return distance(word1, word2, word1.size() - 1, word2.size() - 1);

        // option 2 dp
        int n = word1.size(), m = word2.size();
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; ++i)
            dp[i][0] = i;
        for (int j = 0; j <= m; ++j)
            dp[0][j] = j;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
        return dp[n][m];

        // 相等於 需要刪除多少字符才會變相同
        // 刪除多少字符 也等於 可由求最長公共子序列得知

        int n = word1.size(), m = word2.size();
        int lcs = longestCommonSubsequence(word1, word2);
        return m - lcs + n - lcs;
    }
};