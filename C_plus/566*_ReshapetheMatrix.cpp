class Solution
{
public:
    vector<vector<int> > matrixReshape(vector<vector<int> > &mat, int r, int c)
    {
        int m = mat.size(), n = mat[0].size();
        if (m * n != r * c)
            return mat;
        vector<vector<int> > ret(r, vector<int>(c, 0));
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                int k = i * c + j;
                ret[i][j] = mat[k / n][k % n];
            }
        }
        return ret;


        // option 2 
        vector<vector<int>> ret(r, vector<int>(c,0));
        int n = mat.size(), m = mat[0].size();
        if(m*n !=r*c) return mat;
        int k = 0,  l =0;
        for(int i =0;i<n;++i){
            for(int j=0;j<m;++j){
                if(l==c){
                    k++;
                    l = 0;
                }
                ret[k][l++] = mat[i][j];
            }
        }
        return ret;
    }
};