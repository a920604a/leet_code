/*
 * @Author: yuan
 * @Date: 2021-04-08 08:06:38
 * @LastEditTime: 2021-04-08 08:06:46
 * @FilePath: /C_plus/64_MinimunPathSum.cpp
 */
class Solution
{
public:
    int minPathSum(vector<vector<int> > &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        vector<vector<int> > visit(grid.size(), vector<int>(grid[0].size()));
        visit[0][0] = grid[0][0];
        for (int i = 1; i < grid[0].size(); ++i)
        {
            visit[0][i] = grid[0][i] + visit[0][i - 1];
        }
        for (int i = 1; i < grid.size(); ++i)
        {
            visit[i][0] = grid[i][0] + visit[i - 1][0];
        }

        for (int i = 1; i < visit.size(); ++i)
        {
            for (int j = 1; j < visit[0].size(); ++j)
            {
                visit[i][j] = min(visit[i - 1][j], visit[i][j - 1]) + grid[i][j];
            }
        }
        //         for(int i=0;i<visit.size();++i){
        //             for(int j=0;j<visit[0].size();++j){
        //                 cout<<visit[i][j]<<" ";

        //             }
        //             cout<<endl;
        //         }
        return visit[visit.size() - 1][visit[0].size() - 1];
    }
};