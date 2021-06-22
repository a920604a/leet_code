class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        // 如果最大子陣列在陣列中，取最大。如果在陣列頭與尾，代表最小出現在陣列中，取最小在用陣列和減去最小子陣列，即是case2的最大子陣列
        int local_max = 0, n = nums.size();
        int local_min = 0;
        int sum = 0;
        int global_max = INT_MIN, global_min = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            local_max = max(nums[i], nums[i] + local_max);
            global_max = max(global_max, local_max);
            local_min = min(nums[i], nums[i] + local_min);
            global_min = min(global_min, local_min);
            sum += nums[i];
        }
        if (global_min == sum)
            return global_max; //
        return max(global_max, sum - global_min);
    }
};