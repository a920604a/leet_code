class Solution
{
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int i = m - 1, j = 0;
        while (i >= 0 && j <= n - 1)
        {
            if (target == matrix[i][j])
                return true;
            if (target > matrix[i][j])
                j++;
            else
                i--;
        }
        return false;
    }
};