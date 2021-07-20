class Solution
{
public:
    int rob(vector<int> &nums)
    {
        // 1 2 3 1
        // 1 2 4 4
        // option 1 dp
        // int n = nums.size();
        // if(n==1) return nums[0];
        // vector<int> dp(n,0);
        // dp[0] = nums[0];
        // dp[1] = max(nums[1], dp[0]);
        // for(int i =2;i<n;++i){
        //     dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        // }
        // return dp[n-1];

        // option 1.1 improved dp
        // 根據我的觀察，只需要兩個變數代替dp，因為狀態轉移式子，最多只根據前兩個紀錄
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int a = nums[0];
        int b = max(nums[1], a);
        int cur = 0;
        for (int i = 2; i < n; ++i)
        {
            cur = max(b, a + nums[i]);
            a = b;
            b = cur;
        }
        return max(cur, b);
    }
};