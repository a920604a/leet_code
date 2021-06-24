class Solution
{
public:
    int countSquares(vector<vector<int> > &matrix)
    {
        // option 1 dp
        //         int m = matrix.size(), n=matrix[0].size();
        //         vector<vector<int>> dp(m,vector<int>(n,0));
        //         for(int i= 0 ;i<m;i++){
        //             for(int j=0;j<n;++j){
        //                 if(i==0 || j==0) dp[i][j] = matrix[i][j];
        //                 else if(matrix[i][j]==0) dp[i][j]=0;
        //                 else{  // matrix[i][j] =1
        //                     dp[i][j] = 1+min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
        //                 }
        //             }
        //         }
        //         int ret = 0;
        //         for(int i=0;i<m;i++){
        //             for(int j =0;j<n;++j){
        //                 ret+=dp[i][j];
        //             }
        //         }
        //         return ret;

        // improved option 1
        int m = matrix.size(), n = matrix[0].size(), ret = 0;
        vector<vector<int> > dp = matrix;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i && j && dp[i][j])
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));

                ret += dp[i][j];
            }
        }
        return ret;
    }
};