/*
 * @Author: yuan
 * @Date: 2021-05-01 15:45:23
 * @LastEditTime: 2021-05-01 15:45:23
 * @FilePath: /C_plus/215_KthLargestElementInAnArray.cpp
 */
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};