

int uniquePaths(int m, int n)
{
    int dp[m][n];
    //  1   1   1   1   1   1   1
    //  1   2   3   4   5   6   7
    //  1   3   6   10  15  21  28

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
            dp[i][j] = 0;
    }

    for (int j = 0; j < n; ++j)
        dp[0][j] = 1;
    for (int i = 0; i < m; ++i)
        dp[i][0] = 1;

    for (int i = 1; i < m; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    int ret = dp[m - 1][n - 1];
    return dp[m - 1][n - 1];

    // version 2 pointer 
    int **dp ;
    dp = calloc(m , sizeof(int*)); 
    for(int i=0 ;i<m;++i){
        dp[i] = calloc(n, sizeof(int));
    }
    //  1   1   1   1   1   1   1
    //  1   2   3   4   5   6   7
    //  1   3   6   10  15  21  28
    // for(int i=0;i<m;++i){
    //     for(int j=0;j<n ;++j) printf("%d\t",dp[i][j]);
    //     printf("\n");
    // }
    for(int j=0;j<n;++j) dp[0][j] = 1;
    for(int i=0;i<m;++i) dp[i][0] = 1;
    
    for(int i=1;i<m;++i){
        for(int j=1;j<n;++j){
            // dp[i][j] = dp[i-1][j] + dp[i][j-1];
            *(*(dp+i) + j )= *(*(dp+i-1)+j) + *(*(dp+i)+j-1);
        }
    }
    int ret = dp[m-1][n-1];
    return dp[m-1][n-1];
}