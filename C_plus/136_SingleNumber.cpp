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
        
        // a ^ a = 0 a ^ 0 = a，^有交換率，成對的數字變成０
        int ret = 0;
        for (int i : nums)
            ret ^= i;
        return ret;
    }
};