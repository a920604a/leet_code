/*
 * @Author: yuan
 * @Date: 2021-04-29 13:01:45
 * @LastEditTime: 2021-04-29 13:01:45
 * @FilePath: /leetcode/136_SingleNumber.cpp
 */
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ret = 0;
        for (int i : nums)
            ret ^= i;
        return ret;
    }
};