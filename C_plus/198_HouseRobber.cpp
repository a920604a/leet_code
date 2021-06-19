class Solution
{
public:
    int rob(vector<int> &nums)
    {
        // option 1
        if (nums.size() <= 1)
            return nums.empty() ? 0 : nums[0];
        vector<int> dp = {nums[0], max(nums[0], nums[1])};

        for (int i = 2; i < nums.size(); ++i)
        {
            dp.push_back(max(dp[i - 1], dp[i - 2] + nums[i]));
        }
        return dp.back();

        // option 2 reduce dp
        //         int a=0, b=0;
        //         for(int i=0;i<nums.size();++i){
        //              if(i%2){
        //                  a = max(a+nums[i], b);
        //              }
        //             else{
        //                 b = max(b+nums[i],a);
        //             }

        //         }
        //         return max(a, b);
    }
};