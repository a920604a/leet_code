/*
 * @Author: yuan
 * @Date: 2021-05-03 10:58:48
 * @LastEditTime: 2021-05-03 10:58:48
 * @FilePath: /C_plus/414_ThirdMaximumNumber.cpp
 */
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        long max_1 = LONG_MIN, max_2 = LONG_MIN, max_3 = LONG_MIN;
        for (int i : nums)
        {
            if (i == max_1 || i == max_2 || i == max_3)
                continue;
            if (i > max_1)
            {
                max_3 = max_2;
                max_2 = max_1;
                max_1 = i;
            }
            else if (i > max_2)
            {
                max_3 = max_2;
                max_2 = i;
            }
            else if (i > max_3)
            {
                max_3 = i;
            }
        }
        return max_3 == LONG_MIN ? max_1 : max_3;
    }
};