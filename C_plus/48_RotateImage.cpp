class Solution
{
public:
    void rotate(vector<vector<int> > &matrix)
    {

        // option 1 O(n^2)
        // 4點交換 rotate

        if (matrix.size() == 0 || matrix[0].size() == 0)
            return;

        int m = matrix.size();
        for (int layer = 0; layer < m / 2; ++layer)
        {
            int first = layer;
            int last = m - 1 - layer;
            for (int i = first; i < last; ++i)
            {
                int offset = i - first;
                int top = matrix[first][i];
                matrix[first][i] = matrix[last - offset][first];
                matrix[last - offset][first] = matrix[last][last - offset];
                matrix[last][last - offset] = matrix[i][last];
                matrix[i][last] = top;
            }
        }

        // optnio 2 O(n^2)
        // 1. 以列完單位做reverse
        // 2. transpose

        // reverse(matrix.begin(), matrix.end());
        // int m = matrix.size(), n =matrix[0].size();
        // for(int i=0;i<m;++i){
        //     for(int j =i+1;j<n;++j){
        //         //swap (i,j) (j,i)
        //         swap(matrix[i][j], matrix[j][i]);
        //     }
        // }
    }
};