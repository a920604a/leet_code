/*
 * @Author: yuan
 * @Date: 2021-07-16 14:44:51
 * @LastEditTime: 2021-07-16 14:44:51
 * @FilePath: /leet_code/C_plus/96*_UniqueBinarySearchTrees.cpp
 */
class Solution {
public:
    int numTrees(int n) {
        
        // https://zh.wikipedia.org/wiki/%E5%8D%A1%E5%A1%94%E5%85%B0%E6%95%B0
        // 1 1 2 5 14 42 132 429 1430從０開始
        // (2n)!/((n+1)!* n!)
        // C_{n+1} = \sum{n}{i=0} C_{i}C_{n-i}
        
        
        // C_{n} = \sum{n-1}{i=0} C_{i}*C_{n-1-i}
        // n = 1, C_{1} = C_{0}*C_{0} = 1
        // n = 2, C_{2} = C_{0}*C_{1}  + C_{1}*C_{0} = 2
        // n = 3, C_{3} = C_{0}*C_{2}  + C_{1}*C_{1} + C_{2}*C_{0} = 1*2 + 1*1 + 2*1 = 5
                
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;++i){
            for(int j = 0;j<i;j++){
                dp[i] += dp[j]*dp[i-1-j];
            }
        }
        return dp[n];
    }
};