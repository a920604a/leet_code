class Solution
{
public:
    int dp(vector<vector<int> > &matrix, int i, int j)
    {

        // 非法索引
        if (i < 0 || j < 0 || i > matrix.size() || j >= matrix[0].size())
        {
            return 99999;
        }

        //base case
        if (i == 0)
            return matrix[i][j];

        //
        return matrix[i][j] + min(
                                  dp(matrix, i - 1, j),
                                  min(
                                      dp(matrix, i - 1, j - 1),
                                      dp(matrix, i - 1, j + 1)));
    }

    int dp(vector<vector<int> > &matrix, int i, int j, vector<vector<int> > &memo)
    {
        // 非法索引
        if (i < 0 || j < 0 || i > matrix.size() || j >= matrix[0].size())
        {
            return 99999;
        }

        //base case
        if (i == 0)
            return matrix[i][j];

        // 備忘錄有了，防止重複計算
        if (memo[i][j] != 101)
            return memo[i][j];

        memo[i][j] = matrix[i][j] + min(
                                        dp(matrix, i - 1, j, memo),
                                        min(
                                            dp(matrix, i - 1, j - 1, memo),
                                            dp(matrix, i - 1, j + 1, memo)));

        return memo[i][j];
    }
    int minFallingPathSum(vector<vector<int> > &matrix)
    {
        // option 1 brute force  time out 不愧是medium題目
        // int n = matrix.size();
        // int ret = INT_MAX;
        // for(int i= 0;i<n;++i){
        //     ret = min(ret, dp(matrix, n-1, i ));
        // }
        // return ret;

        // option 2 memo
        //         int n = matrix.size(), m = matrix[0].size();
        //         int ret = INT_MAX;
        //         vector<vector<int>>memo(n, vector<int>(m,101));
        //         // 初始化備忘錄

        //         for(int i= 0;i<n;++i){
        //             ret = min(ret, dp(matrix, n-1, i , memo));
        //         }
        //         return ret;

        // option 3 dp
        int n = matrix.size(), m = matrix[0].size();
        if (n == 1)
            return matrix[0][0];
        vector<vector<int> > dp = matrix;
        int ret = INT_MAX;
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (j == 0)
                    dp[i][j] += min(dp[i - 1][j], dp[i - 1][j + 1]);
                else if (j == m - 1)
                    dp[i][j] += min(dp[i - 1][j - 1], dp[i - 1][j]);
                else
                    dp[i][j] += min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i - 1][j + 1]));

                if (i == n - 1)
                    ret = min(ret, dp[i][j]);
            }
        }

        return ret;
    }
};