/*
 * @Author: yuan
 * @Date: 2021-05-02 09:13:21
 * @LastEditTime: 2021-05-02 09:13:21
 * @FilePath: /C_plus/258_AddDigits.cpp
 */
class Solution
{
public:
    int addDigits(int num)
    {
        int tmp = num;
        while (tmp)
        {
            if (num < 10)
                break;
            tmp = 0;
            while (num)
            {
                tmp += (num % 10);
                num /= 10;
            }
            num = tmp;
        }
        return num;
    }
};