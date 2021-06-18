class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ret = {1};
        for (int i = 1; i <= rowIndex; ++i)
        {
            vector<int> temp = ret;

            int var = temp[0];
            for (int j = 1; j < temp.size(); ++j)
            {
                int copy = temp[j];
                temp[j] = temp[j] + var;
                var = copy;
            }
            ret = temp;
            ret.push_back(1);
        }

        return ret;
    }
};