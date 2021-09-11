class Solution
{
public:
    vector<vector<int> > memo;
    int dp(vector<vector<int> > &dungeon, int i, int j)
    {
        int m = dungeon.size(), n = dungeon[0].size();

        // base case
        if (i == m - 1 && j == n - 1)
        {
            // 保證騎士落地不死就行了
            return dungeon[i][j] > 0 ? 1 : -dungeon[i][j] + 1;
        }

        if (i == m || j == n)
            return INT_MAX;

        if (memo[i][j] != -1)
            return memo[i][j];

        int ret = min(dp(dungeon, i, j + 1),
                      dp(dungeon, i + 1, j)) -
                  dungeon[i][j];

        memo[i][j] = ret <= 0 ? 1 : ret;

        return memo[i][j];
    }
    int calculateMinimumHP(vector<vector<int> > &dungeon)
    {
        // backtracking
        int m = dungeon.size(), n = dungeon[0].size();
        memo = vector<vector<int> >(m, vector<int>(n, -1));

        return dp(dungeon, 0, 0);

        // option 1 dp
        // 7    5   2
        // 6    11  5
        // 1    1   6
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int> > dp(n, vector<int>(m, 0));
        // base case
        dp[n - 1][m - 1] = max(1, 1 - dungeon[n - 1][m - 1]);
        for (int j = m - 2; j > -1; j--)
        {
            dp[n - 1][j] = max(1, dp[n - 1][j + 1] - dungeon[n - 1][j]);
        }

        for (int i = n - 2; i > -1; i--)
        {
            dp[i][m - 1] = max(1, dp[i + 1][m - 1] - dungeon[i][m - 1]);
        }

        //
        for (int i = n - 2; i > -1; i--)
        {
            for (int j = m - 2; j > -1; j--)
            {
                dp[i][j] = min(max(1, dp[i + 1][j] - dungeon[i][j]),
                               max(1, dp[i][j + 1] - dungeon[i][j]));
            }
        }

        return dp[0][0];
    }
};