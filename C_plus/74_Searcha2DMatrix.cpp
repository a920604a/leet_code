/*
 * @Author: yuan
 * @Date: 2021-05-02 08:41:27
 * @LastEditTime: 2021-05-02 08:41:27
 * @FilePath: /C_plus/74_Searcha2DMatrix.cpp
 */
class Solution
{
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target)
    {
        int m = matrix.size() - 1;
        int n = matrix[0].size() - 1;
        int i = m, j = 0;
        while (i >= 0 && j <= n)
        {
            if (target == matrix[i][j])
                return true;
            else if (target > matrix[i][j])
                j++;
            else if (target < matrix[i][j])
                i--;
        }
        return false;
    }
};