class Solution
{
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();

        int i = m - 1, j = 0;
        while (j <= n - 1 && i > -1)
        {
            if (matrix[i][j] == target)
                return true;
            else if (target > matrix[i][j])
                j++;
            else
                i--;
        }
        return false;
    }
};