class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {

        //    1   -2  3   -2 => total 0
        //max 1   -1  3   -1
        //min 1   -2  1   -2
        // ans = max( 3 , sum - -2)

        //    5   -3  5 => sum = 7
        //max 5   -2  5
        //min 5   -3  -2
        //ans = max( 5 , 7 - -3)

        //    3   -1  2   -1  => sum = 3
        //max 3    2  4    3
        //min 3   -1  1    -1
        // ans = max(4, 3 - -1)
        // 如果最大子陣列在陣列中，取最大。如果在陣列頭與尾，代表最小出現在陣列中，取最小在用陣列和減去最小子陣列，即是case2的最大子陣列
        int ans = -30000, n = nums.size(), sum = 0;
        int local_max = 0, local_min = 0, global_max = INT_MIN, global_min = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            local_max = max(local_max + nums[i], nums[i]);
            local_min = min(local_min + nums[i], nums[i]);
            global_max = max(local_max, global_max);
            global_min = min(local_min, global_min);
        }
        if (global_min == sum)
            return global_max;
        return max(global_max, sum - global_min);
    }
};