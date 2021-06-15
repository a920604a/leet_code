/*
 * @Author: yuan
 * @Date: 2021-04-01 19:03:06
 * @LastEditTime: 2021-04-01 19:03:16
 * @FilePath: /leetcode/55_JumpGame.cpp
 */
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        vector<bool> canReach(nums.size(), false);
        canReach[0] = true;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (canReach[i])
            {
                for (int j = i + 1; j <= nums[i] + i && j < nums.size(); j++)
                {
                    canReach[j] = true;
                }
            }
        }
        return canReach[nums.size() - 1];
    }
};