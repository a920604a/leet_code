class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        // option 0 time out
        //      2   3   1   1   4
        //      f   t   t
        //      f   t   t   t   t
        
        // int n = nums.size();
        // vector<int> dp(n,false) ;
        // dp[0] = true;
        // for(int i=0;i<n ; ++i){
        //     for(int j =i+1;j<=i + nums[i] && j<n; j++){
        //         dp[j] = dp[i];
        //     }
        // }
        // return dp[n-1];


        // option 1 dp策略
        //  2   3   1   1   4
        //  0   0   0   0   0    initialize dp
        //  0   1   2   1   0    剩餘最大跳力，如果剩餘跳力小於0，返回false。;
        // dp[i] = max(nums[i-1]-1, dp[i-1]-1)

        //  3   2   1   0   4
        //  0   2   1   0   -1

        //  1   0   1   0
        //  0   0   -1  ..
        // int n = nums.size();
        // vector<int> dp(n,0);
        // for(int i=1;i<n;++i){
        //     dp[i] = max(nums[i-1]-1, dp[i-1]-1) ;
        //     if(dp[i]<0) return false;
        // }
        // return true;

        // option 2 貪心策略
        //            2   3   1   1   4
        // i =        0   1   2   3   4
        // canReach = 2   4   4   4     canReach = max(i+nums[i], canReach)

        //              0   2   3
        //  i =         0   1   2
        // canReach =   0   3(X)   5(X)   加入判斷條件  canReach <= i 表示碰到0返回false

        //               1   0   1   0
        // i =           0   1   2   3
        // canReach      1   1   X   X

        int n = nums.size();
        int canReach = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            canReach = max(i + nums[i], canReach);
            if (canReach <= i)
                return false;
        }
        return canReach >= n - 1 ? true : false;
    }
};