/*
 * @Author: yuan
 * @Date: 2021-05-01 18:11:56
 * @LastEditTime: 2021-05-01 18:11:56
 * @FilePath: /C_plus/221_MaximalSquare.cpp
 */
class Solution
{
public:
    int maximalSquare(vector<vector<char> > &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int> > dp(m, vector<int>(n));
        int ret = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = matrix[i][j] - '0';
                else if (matrix[i][j] == '0')
                    dp[i][j] = 0;
                else
                {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    ret = max(ret, dp[i][j]);
                }
                ret = max(ret, dp[i][j]);
            }
        }
        return ret * ret;
    }
};