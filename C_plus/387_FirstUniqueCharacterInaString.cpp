/*
 * @Author: yuan
 * @Date: 2021-05-02 22:43:42
 * @LastEditTime: 2021-05-02 22:43:43
 * @FilePath: /C_plus/387_FirstUniqueCharacterInaString.cpp
 */
class Solution
{
public:
    int firstUniqChar(string s)
    {
        map<char, int> m;
        for (char c : s)
            m[c]++;
        // for(auto c:m) cout<<c.first<<" "<<c.second<<endl;
        for (int i = 0; i < s.size(); ++i)
        {
            if (m[s[i]] == 1)
                return i;
        }

        return -1;
    }
};