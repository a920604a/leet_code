/*
 * @Author: yuan
 * @Date: 2021-04-29 15:40:08
 * @LastEditTime: 2021-04-29 15:40:08
 * @FilePath: /C_plus/167_TwoSum.cpp
 */
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        map<int, int> m;
        for (int i = 0; i < numbers.size(); ++i)
        {
            if (m.find(target - numbers[i]) != m.end())
            {

                return {m[target - numbers[i]], i + 1};
            }
            m[numbers[i]] = i + 1;
        }
        return {};
    }
};