/*
 * @Author: yuan
 * @Date: 2021-05-01 16:05:37
 * @LastEditTime: 2021-05-01 16:05:46
 * @FilePath: /C_plus/218_ContainsDuplicateII.cpp
 */
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (m.find(nums[i]) != m.end() && abs(i - m[nums[i]]) <= k)
                return true;
            m[nums[i]] = i;
        }
        return false;
    }
};