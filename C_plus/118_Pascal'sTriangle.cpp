class Solution
{
public:
    vector<vector<int> > generate(int numRows)
    {
        vector<vector<int> > ret = {{1}};
        for (int i = 2; i <= numRows; ++i)
        {
            vector<int> temp = ret[ret.size() - 1];
            int var = temp[0];
            for (int j = 1; j < temp.size(); ++j)
            {
                int copy = temp[j];
                temp[j] = temp[j] + var;
                var = copy;
            }

            temp.push_back(1);
            ret.push_back(temp);
        }

        return ret;
    }
};