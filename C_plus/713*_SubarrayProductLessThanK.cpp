class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        // sliding window
        int n = nums.size();
        int prod = 1, ret = 0;
        int l = 0;
        for (int r = 0; r < n; ++r)
        {
            prod *= nums[r];

            while (l <= r && prod >= k)
                prod /= nums[l++];

            ret += (r - l + 1);
        }
        return ret;
    }
};