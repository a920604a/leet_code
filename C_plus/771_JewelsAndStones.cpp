/*
 * @Author: yuan
 * @Date: 2021-05-04 17:31:04
 * @LastEditTime: 2021-05-04 17:31:05
 * @FilePath: /C_plus/771_JewelsAndStones.cpp
 */
class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        int ret = 0;
        map<char, int> m;
        for (char c : stones)
            m[c]++;
        for (char c : jewels)
            ret += (m[c]);
        return ret;
    }
};