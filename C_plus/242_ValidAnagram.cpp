/*
 * @Author: yuan
 * @Date: 2021-05-02 09:04:39
 * @LastEditTime: 2021-05-02 09:04:39
 * @FilePath: /C_plus/242_ValidAnagram.cpp
 */
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        //         vector<int> v1;
        //         vector<int> v2;
        //         if(s.size()!=t.size()) return false;
        //         for(int i=0;i<s.size();++i)  v1.push_back(s[i]-'a');
        //         for(int i=0;i<t.size();++i)  v2.push_back(t[i]-'a');
        //         sort(v1.begin(), v1.end());
        //         sort(v2.begin(), v2.end());

        //         for(int i=0;i<v1.size();++i){
        //             if(v1[i]!=v2[i]) return false;
        //         }
        //         return true;
        vector<int> v(26, 0);
        for (char c : s)
            v[c - 'a']++;
        for (char c : t)
            v[c - 'a']--;
        for (int i : v)
        {
            if (i != 0)
                return false;
        }
        return true;
    }
};