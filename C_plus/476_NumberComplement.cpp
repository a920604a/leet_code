/*
 * @Author: yuan
 * @Date: 2021-05-04 11:28:34
 * @LastEditTime: 2021-05-04 12:38:10
 * @FilePath: /C_plus/476_NumberComplement.cpp
 */
class Solution
{
public:
    int findComplement(int num)
    {
        unsigned mask = ~0;
        while (num & mask)
            mask <<= 1;
        return ~mask & ~num;
    }
};