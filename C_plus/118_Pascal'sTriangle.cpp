class Solution
{
public:
    vector<vector<int> > generate(int numRows)
    {
        vector<vector<int> > ret;
        ret.push_back({1});
        for (int i = 2; i <= numRows; ++i)
        {
            vector<int> tmp = ret[ret.size() - 1];
            tmp.push_back(1);
            for (int j = 1; j < i - 1; ++j)
            {
                tmp[j] = ret[ret.size() - 1][j] + ret[ret.size() - 1][j - 1];
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};