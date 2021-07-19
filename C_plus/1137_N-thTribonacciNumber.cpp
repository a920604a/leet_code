class Solution {
public:
    int tribonacci(int n) {
        // option 1 
        // if(n==0) return 0;
        // if(n==1 || n==2) return 1;
        // int a = 0, b=1,c=1,ret;
        // for(int i=3;i<=n;++i){
        //     ret = a+b+c;
        //     a = b;
        //     b = c;
        //     c = ret;
        // }
        // return ret;
        
        // option 2 dp;
        if(n==0) return 0;
        vector<int> dp(n+1,1);
        if(n==1 || n==2) return dp[n];
        dp[0] = 0;
        
        for(int i=3;i<=n;++i){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
    }
};