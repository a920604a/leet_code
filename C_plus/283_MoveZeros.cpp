/*
 * @Author: yuan
 * @Date: 2021-05-02 11:13:00
 * @LastEditTime: 2021-05-02 11:13:10
 * @FilePath: /C_plus/283_MoveZeros.cpp
 */
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int p1 = 0, p2 = 0;
        int tmp = 0;
        while (p2 < nums.size())
        {
            if (nums[p2])
            {
                int tmp = nums[p1];
                nums[p1] = nums[p2];
                nums[p2] = tmp;
                p1++;
            }
            p2++;
        }
    }
};