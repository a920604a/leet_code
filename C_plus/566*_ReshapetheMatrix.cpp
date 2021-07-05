class Solution
{
public:
    vector<vector<int> > matrixReshape(vector<vector<int> > &mat, int r, int c)
    {
        int m = mat.size(), n = mat[0].size();
        if (m * n != r * c)
            return mat;
        vector<vector<int> > ret(r, vector<int>(c, 0));
        // M[i][j]=M[n*i+j]
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                int k = i * c + j;
                ret[i][j] = mat[k / n][k % n];
            }
        }
        return ret;
    }
};