class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2,0));
        vector<int> points(n+2, 0);
        points[0] = 1, points[n+1] = 1;
        for(int i=1;i<=n;++i) points[i] = nums[i-1];
        
        // dp[i][j] = dp[i][k] + dp[k][j] + nums[i]*nums[k]*nums[j];
        //              3   1   5   8
        //      0   0
        //      0   0
        //  3
        //  1
        //  5
        //  8
        
        // i 從下往上
        for(int i=n; i>=0 ;i--){
            // j 從左往右
            for(int j = i+1;j< n+2 ; ++j){
                // 最後戳破 的氣球是哪一顆
                for(int k = i+1; k<j ;++k){
                    dp[i][j] = max(dp[i][j], 
                                   dp[i][k] + dp[k][j] + points[i]*points[k]*points[j]
                                  );
                }
            }
        }
        return dp[0][n+1];
    }
};