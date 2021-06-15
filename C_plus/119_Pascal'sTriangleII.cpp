class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> tmp;
        for (int i = 0; i <= rowIndex; ++i)
        {

            tmp.push_back(1);
            int temp1 = tmp[0], temp2 = tmp[0];
            for (int j = 1; j <= i - 1; ++j)
            {
                temp1 = tmp[j];
                tmp[j] = tmp[j] + temp2;
                temp2 = temp1;
            }
        }
        return tmp;
    }
};