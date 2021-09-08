class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        //  1   2   3   4   5   6
        //  0   0   1   2   3   4

        //  1   3   5   7   9   11  13
        //  0   0   1   2   3   4   5

        //  1   2   3   8   9   10
        //  0   0   1   0   0   1

        // option 1 dp
        // int n = nums.size();
        // vector<int> dp(n,0);
        // int ret = 0;
        // for(int i=2;i<n;++i){
        //     int diff = nums[i-1] - nums[i-2];
        //     if(diff == nums[i] - nums[i-1]){
        //         dp[i] = dp[i - 1] + 1;
        //     }
        //     ret += dp[i];
        // }
        // return ret;

        // option 1 reduce dp
        int ret = 0, cur = 0, n = nums.size();
        for (int i = 2; i < n; ++i)
        {
            if (nums[i - 1] - nums[i - 2] == nums[i] - nums[i - 1])
            {
                cur++;
            }
            else
            {
                cur = 0;
            }
            ret += cur;
        }
        return ret;
    }
};