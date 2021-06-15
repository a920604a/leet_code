/*
 * @Author: yuan
 * @Date: 2021-05-01 19:12:33
 * @LastEditTime: 2021-05-01 19:12:33
 * @FilePath: /C_plus/231_PowerOfTwo.cpp
 */
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        int ret = 0;
        if (n < 1)
            return false;
        if (n == 1)
            return true;
        while (n >= 2)
        {
            if (n % 2 != 0)
                return false;
            n /= 2;
        }
        return n == 1 ? true : false;
    }
};