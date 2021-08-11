class Solution
{
public:
    void backtrack(vector<int> &nums, int i, int target, int &ret)
    {
        //base case 結束條件
        if (i == nums.size())
        {
            if (target == 0)
                ret++;
            return;
        }

        // 選擇負號
        target += nums[i];                   //做選擇
        backtrack(nums, i + 1, target, ret); // 窮舉所有選擇
        target -= nums[i];                   // 撤銷選擇
        //backtrack(nums, i+1, target+nums[i], ret);

        // 選擇正號
        target -= nums[i];                   //做選擇
        backtrack(nums, i + 1, target, ret); // 窮舉所有選擇
        target += nums[i];                   // 撤銷選擇
        //backtrack(nums, i+1, target-nums[i], ret);
    }

    int dp(vector<int> &nums, int i, int target, unordered_map<string, int> &memo)
    {

        //base case 結束條件
        if (i == nums.size())
        {
            if (target == 0)
                return 1;
            return 0;
        }

        // 轉為字串
        string key = to_string(i) + "," + to_string(target);

        // 用memo避免重複計算
        if (memo.count(key))
            return memo[key];

        // 選擇正號與服好的排列組合，窮舉
        int result = dp(nums, i + 1, target - nums[i], memo) +
                     dp(nums, i + 1, target + nums[i], memo);
        memo[key] = result;
        return result;
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        //         def backtrack(路径, 选择列表):
        //         if 满足结束条件:
        //             result.add(路径)
        //             return

        //         for 选择 in 选择列表:
        //             做选择
        //             backtrack(路径, 选择列表)
        //             撤销选择
        // option 1 O(2^N) time
        // if(nums.size()==0) return 0;
        // int ret =0;
        // backtrack(nums, 0, target, ret);
        // return ret;

        //option 2 memo 消除重疊子問題
        if (nums.size() == 0)
            return 0;
        unordered_map<string, int> memo;

        return dp(nums, 0, target, memo);

        // option 3
        // 將 nums 分成兩個集合 A B分別代表 分配+  - 的個數，那麼
        // sum(A) - sum(B) = target
        // sum(A) = target + sum(B)
        // sum(A) + sum(A) = target + sum(B) + sum(A)
        // 2 * sum(A) = target + sum(nums)
        // 將問題變成 nums 中存在幾個子集 A，使得A 中元素的和為 (target + sum(nums))/2 = 4
        // dp 背包問題，容量為 4 ，現在給你 N 個物品，第 i 個物品中 nums[i-1]，每個物品只有一個，請問有幾種方法恰好能滿背包
        //sum = 0   1   2   3   4
        //      1   0   0   0   0
        //1     1   1   0   0   0
        //1     1   2   1   0   0
        //1     1   3   3   1   0
        //1     1   4   6   4   1
        //1     1   5   10  10  5
        // 背包問題 通解 if( j >= nums[i-1]) dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]];
        // 把 第 i-1 物品裝入背包 或不裝入背包的總方法數

        //         int sum =0;
        //         int n = nums.size();
        //         for(int i = 0; i < n; i++)
        //              sum += nums[i];
        //         // 不可能存在合法子集
        //         if(sum < target || (sum + target)%2 == 1 ) return 0;
        //         sum = (sum + target)/2;

        //         vector<vector<int>> dp(n+1, vector<int>(sum+1,0));
        //         for(int i=0 ;i<=n ;++i) dp[i][0] = 1;
        //         for(int i = 1;i<=n;++i){
        //             for(int j=0;j<=sum ; ++j){
        //                 if((j >= nums[i-1])) dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]];
        //                 else dp[i][j] = dp[i-1][j];
        //             }

        //         }
        //         return dp[n][sum];

        // option 4 reduce dp
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            sum += nums[i];
        if (sum < target || (sum + target) % 2 == 1)
            return 0;
        sum = (sum + target) / 2;
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = sum; j >= 0; j--)
            {
                // 注意 背包問題化為一維時，要反向搜尋
                if (j >= nums[i - 1])
                    dp[j] += dp[j - nums[i - 1]];
            }
        }

        return dp[sum];
    }
};