/*
 * @Author: yuan
 * @Date: 2021-04-08 10:35:09
 * @LastEditTime: 2021-04-08 10:35:36
 * @FilePath: /C_plus/67_AddBinary.cpp
 */
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string ret = "";
        int aa = a.size(), bb = b.size();
        int len = max(aa, bb);
        for (int i = 0; i < len - aa; ++i)
        {
            a.insert(a.begin(), '0');
        }
        for (int i = 0; i < len - bb; ++i)
        {
            b.insert(b.begin(), '0');
        }
        int sum = 0;
        for (int i = len - 1; i >= 0; i--, sum /= 2)
        {
            sum += (a[i] - '0' + b[i] - '0');
            if (sum == 0 || sum == 2)
            {
                ret.insert(ret.begin(), '0');
            }
            else if (sum == 1 || sum == 3)
            {
                ret.insert(ret.begin(), '1');
            }
        }
        if (sum == 2)
        {
            ret.insert(ret.begin(), '0');
        }
        else if (sum == 1 || sum == 3)
        {
            ret.insert(ret.begin(), '1');
        }
        return ret;
    }
};