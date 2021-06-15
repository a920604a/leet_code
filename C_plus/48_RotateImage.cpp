class Solution
{
public:
    void rotate(vector<vector<int> > &matrix)
    {
        // row reverse
        int rows = matrix.size() - 1;
        for (int i = 0; i < matrix.size() / 2; ++i)
        {
            vector<int> tmp = matrix[i];
            matrix[i] = matrix[rows - i];
            matrix[rows - i] = tmp;
        }

        //transpose
        for (int i = 0; i <= rows; ++i)
        {
            for (int j = i + 1; j <= rows; ++j)
            {
                // switch [i][j] [j][i]
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
};