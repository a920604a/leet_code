class Solution
{
public:
    void setZeroes(vector<vector<int> > &matrix)
    {

        vector<pair<int, int> > collect;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                    collect.push_back(make_pair(i, j));
            }
        }

        for (auto a : collect)
        {
            int x = a.first;
            int y = a.second;
            for (int i = 0; i < n; ++i)
                matrix[x][i] = 0;
            for (int i = 0; i < m; ++i)
                matrix[i][y] = 0;
        }
    }
};