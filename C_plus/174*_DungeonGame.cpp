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
        int m = dungeon.size(), n = dungeon[0].size();
        memo = vector<vector<int> >(m, vector<int>(n, -1));

        return dp(dungeon, 0, 0);
    }
};