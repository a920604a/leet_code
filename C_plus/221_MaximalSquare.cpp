class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m , vector<int>(n,0));

        for(int i =0;i<m;++i){
            for(int j =0;j<n;++j){
                dp[i][j] = matrix[i][j] -'0';
            }
        }
        
        int ret = 0;
        for(int i =0;i<m;++i){
            for(int j =0;j<n;++j){
                if(i==0 || j==0 || dp[i][j]==0) continue;
                else{
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]) )+1;
                }
                
            }
        }
        
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                ret = max(ret, dp[i][j]);
            }
            cout<<endl;
        }
        
        return ret*ret;
    }
};