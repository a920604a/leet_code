/*
 * @Author: yuan
 * @Date: 2021-05-01 23:59:27
 * @LastEditTime: 2021-05-01 23:59:27
 * @FilePath: /C_plus/238_ProductOrArrayExceptSelf.cpp
 */
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        for (int i = 1; i < n; ++i)
        {
            left[i] = nums[i - 1] * left[i - 1];
        }
        for (int j = n - 2; j >= 0; --j)
        {
            right[j] = nums[j + 1] * right[j + 1];
        }
        vector<int> ret(n, 1);
        for (int i = 0; i < n; ++i)
        {
            ret[i] = left[i] * right[i];
        }

        return ret;
    }
};