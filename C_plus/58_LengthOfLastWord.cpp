/*
 * @Author: yuan
 * @Date: 2021-04-07 21:36:20
 * @LastEditTime: 2021-04-07 21:46:29
 * @FilePath: /C_plus/58_LengthOfLastWord.cpp
 */
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        if (s == " ")
            return 0;
        int right = s.size() - 1;
        int left = 0;
        while (s[right] == ' ' && right > left)
            right--;
        int res = 0;
        for (int i = left; i <= right; ++i)
        {
            if (s[i] == ' ')
            {
                res = 0;
            }
            else
                res++;
        }
        return res;
    }
};