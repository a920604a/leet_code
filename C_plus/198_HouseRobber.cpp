/*
 * @Author: yuan
 * @Date: 2021-05-01 10:11:32
 * @LastEditTime: 2021-05-01 10:11:39
 * @FilePath: /leetcode/198_HouseRobber.cpp
 */
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int a = 0;
        int b = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i % 2 == 0)
            {
                a = max(a + nums[i], b);
            }
            else
            {
                b = max(b + nums[i], a);
            }
        }
        return max(a, b);
    }
};