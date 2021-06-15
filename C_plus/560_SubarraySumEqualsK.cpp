/*
 * @Author: yuan
 * @Date: 2021-05-04 15:11:03
 * @LastEditTime: 2021-05-04 15:11:11
 * @FilePath: /C_plus/560_SubarraySumEqualsK.cpp
 */
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        map<int, int> m;
        int sum = 0, ret = 0;
        m[0]++;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            if (m.find(sum - k) != m.end())
                ret += m[sum - k];
            m[sum]++;
        }
        return ret;
    }
};