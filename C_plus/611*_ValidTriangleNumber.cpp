/*
 * @Author: yuan
 * @Date: 2021-07-15 22:23:40
 * @LastEditTime: 2021-07-15 22:23:41
 * @FilePath: /leet_code/C_plus/611*_ValidTriangleNumber.cpp
 */
class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ret = 0, n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; j++)
            {
                int sum = nums[i] + nums[j];
                int left = j + 1, right = n;
                while (left < right)
                {
                    int mid = left + (right - left) / 2;
                    if (nums[mid] < sum)
                        left = mid + 1;
                    else
                        right = mid;
                }

                ret += (right - 1 - j);
            }
        }
        return ret;
    }
};