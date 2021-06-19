/*
 * @Author: yuan
 * @Date: 2021-05-01 11:13:39
 * @LastEditTime: 2021-05-01 11:13:39
 * @FilePath: /leetcode/200_NumberOfIslands.cpp
 */
class Solution
{
public:
    int numIslands(vector<vector<char> > &grid)
    {
        int ret = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool> > visit(m, vresector<bool>(n));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '0' || visit[i][j])
                    continue;
                helper(grid, visit, i, j);
                ret++;
            }
        }

        return ret;
    }

    void helper(vector<vector<char> > &grid, vector<vector<bool> > &ret, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || ret[i][j] || grid[i][j] == '0')
            return;
        ret[i][j] = true;
        helper(grid, ret, i - 1, j);
        helper(grid, ret, i + 1, j);
        helper(grid, ret, i, j - 1);
        helper(grid, ret, i, j + 1);
    }
};