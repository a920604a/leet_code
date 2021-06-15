/*
 * @Author: yuan
 * @Date: 2021-05-05 14:11:24
 * @LastEditTime: 2021-05-05 14:11:24
 * @FilePath: /C_plus/997_FindtheTownJudge.cpp
 */
class Solution
{
public:
    int findJudge(int N, vector<vector<int> > &trust)
    {
        vector<int> ret(N, 0);
        for (vector<int> p : trust)
        {
            ret[p.back() - 1]++;
            ret[p.front() - 1]--;
        }
        for (int i = 0; i < ret.size(); ++i)
        {
            if (ret[i] == N - 1)
                return i + 1;
        }
        return -1;
    }
};