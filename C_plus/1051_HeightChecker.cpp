/*
 * @Author: yuan
 * @Date: 2021-05-05 16:13:24
 * @LastEditTime: 2021-05-05 16:13:32
 * @FilePath: /C_plus/1051_HeightChecker.cpp
 */
class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        set<int> s;
        vector<int> ret = heights;
        sort(ret.begin(), ret.end());

        for (int i = 0; i < ret.size(); ++i)
        {
            if (ret[i] != heights[i])
                s.insert(i);
        }

        return s.size();
    }
};