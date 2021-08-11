class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        // 0-1 背包問題
        // 狀態 = 背包重量 與 可選擇物品
        //         int[][] dp[N+1][W+1]  // N+1 前n+1個物品  W+1 w背包容量
        //         dp[0][..] = 0
        //         dp[..][0] = 0

        //         for i in [1..N]:
        //             for w in [1..W]:
        //                 dp[i][w] = max(
        //                     把物品 i 装进背包,
        //                     不把物品 i 装进背包
        //                 )
        //         return dp[N][W]

        // 可容納重量為 sum/2 的背包，有n個物品，每個物品重量為nums[i]
        
        
        // 維護一個dp，表示數組是否能取出若干個數，其和為i
        // nums[i-1]  第i個物品重量
        //  dp[i - 1][j-nums[i-1]] 裝了第i個物品，背包剩餘重量 j - nums[i-1] 限制下能否被裝滿
        //       0   1   2   3   4   5   6   7   8   9   10  11       , target = 11
        //       t   f   f   f   f   f   f   f   f   f   f   f
        //   1   t   t   f   f   f   f   f   f   f   f   f   f
        //   5   t   t   f   f   f   t   t   f   f   f   f   f
        //   11  t   t   f   f   f   t   t   f   f   f   f   t
        //   5   t   t   f   f   f   t   t   f   f   f   t   t
        //         int sum = accumulate(nums.begin(), nums.end(), 0);
        //         // 總和為奇數，不可能分割成兩個相等集合
        //         if(sum &1) return false;
        //         int target = sum/2, n = nums.size();
        //         vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));
        //         // base case
        //         for(int i=0;i<=n;++i) dp[i][0]  = true;

        //         for(int i= 1;i<=n;++i){
        //             for(int j =1;j<=target ;++j){
        //                 if( j- nums[i-1] < 0){
        //                     // 背包容量不足，不能再裝第i個物品
        //                     dp[i][j] = dp[i-1][j];
        //                 }
        //                 else{
        //                     //裝或不裝入背包
        //                     dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
        //                 }
        //             }
        //         }

        //         return dp[n][target];

        // option 2 壓縮dp
        int sum = 0, n = nums.size();
        for (int n : nums)
            sum += n;
        if (sum % 2 != 0)
            return false;
        sum /= 2;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; ++i)
        {
            for (int j = sum; j >= 0; j--)
            {
                // 背包問題 一維dp 須反向搜尋
                if (j - nums[i] >= 0)
                    dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[sum];
    }
};