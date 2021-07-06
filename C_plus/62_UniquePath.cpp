class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // option 1 dp
        //         vector<vector<int>> dp(m,vector<int>(n,1));

        //         for(int i =1;i<m;i++){
        //             for(int j =1;j<n;++j){
        //                 dp[i][j] = dp[i-1][j] + dp[i][j-1];
        //             }
        //         }
        //         return dp[m-1][n-1];

        // option 2 壓縮dp
        // vector<int> dp(n,1);
        // for(int i=1;i<m;++i){
        //     for(int j = 1;j<n;++j){
        //         dp[j] = dp[j-1] + dp[j];
        //     }
        // }
        // return dp[n-1];

        // option 3 math
        // decrease both m & n by 1 and apply following formula:
        // (m+n)! / (m! * n!)

        if (m == 1 || n == 1)
            return 1;
        m--;
        n--;
        if (m < n)
        { // Swap, so that m is the bigger number
            m = m + n;
            n = m - n;
            m = m - n;
        }
        long res = 1;
        int j = 1;
        for (int i = m + 1; i <= m + n; i++, j++)
        { // Instead of taking factorial, keep on multiply & divide
            res *= i;
            res /= j;
        }
        return (int)res;
    }
};