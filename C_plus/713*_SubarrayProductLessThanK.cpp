class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        // sliding window

        int ret = 0, n = nums.size();
        int prod = 1, left = 0;
        for (int i = 0; i < n; ++i)
        {
            prod *= nums[i];
            while (left <= i && prod >= k)
                prod /= nums[left++];
            ret += (i - left + 1);
        }
        return ret;
    }
};