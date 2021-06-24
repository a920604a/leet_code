class Solution
{
public:
    int findJudge(int n, vector<vector<int> > &trust)
    {
        vector<int> ret(n, 0);
        for (vector<int> p : trust)
        {
            ret[p[1] - 1]++;
            ret[p[0] - 1]--;
        }

        for (int i = 0; i < ret.size(); ++i)
        {
            if (ret[i] == n - 1)
                return i + 1;
        }
        return -1;
    }
};