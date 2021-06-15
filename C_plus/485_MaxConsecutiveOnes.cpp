/*
 * @Author: yuan
 * @Date: 2021-05-04 13:03:51
 * @LastEditTime: 2021-05-04 13:04:03
 * @FilePath: /C_plus/485_MaxConsecutiveOnes.cpp
 */
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int ret = 0;
        int tmp = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
                tmp = 0;
            else
                tmp++;
            ret = max(ret, tmp);
        }
        return ret;
    }
};