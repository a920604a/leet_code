/*
 * @Author: yuan
 * @Date: 2021-04-08 10:53:47
 * @LastEditTime: 2021-04-08 12:01:00
 * @FilePath: /C_plus/70_ClimbingStairs.cpp
 */
class Solution
{
public:
    int climbStairs(int n)
    { // 1 2 3 5 8

        if (n <= 3)
            return n;

        int a = 1, b = 2;
        int c;
        for (int i = 3; i <= n; ++i)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};