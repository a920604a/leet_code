/*
 * @Author: yuan
 * @Date: 2021-05-02 11:55:34
 * @LastEditTime: 2021-05-02 11:55:35
 * @FilePath: /C_plus/344_ReverseString.cpp
 */
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        char c = ' ';
        int size = s.size();
        int n = size % 2 == 0 ? size / 2 - 1 : size / 2;
        while (n > -1)
        {
            // swap s[n] s[size-1-n]
            c = s[n];
            s[n] = s[size - 1 - n];
            s[size - 1 - n] = c;
            n--;
        }
    }
};