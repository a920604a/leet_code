/*
 * @Author: yuan
 * @Date: 2021-05-09 15:23:49
 * @LastEditTime: 2021-05-09 15:23:49
 * @FilePath: /C_plus/38_CountandSay.cpp
 */
class Solution
{
public:
    string countAndSay(int n)
    {
        string ret = "1";
        for (int i = 2; i <= n; ++i)
        {
            ret = say(ret);
            // cout<<ret<<endl;
        }
        return ret;
    }
    string say(string str)
    {
        int count = 1;
        int i = 1;
        char c = str[0];
        string ret = "";
        while (i < str.size())
        {
            if (str[i] == c)
                count++;
            else if (str[i] != c)
            {

                ret += (to_string(count) + str[i - 1]);
                count = 1;
                c = str[i];
            }
            ++i;
        }
        ret += (to_string(count) + str[i - 1]);
        return ret;
    }
};