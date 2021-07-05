class Solution
{
public:
    void setZeroes(vector<vector<int> > &matrix)
    {
        // option 1 O(n*m) space
        //         int m = matrix.size(), n = matrix[0].size();
        //         vector<pair<int,int>> coor;
        //         for(int i = 0;i<m;++i){
        //             for(int j =0;j<n;++j){
        //                 if(matrix[i][j]==0) coor.push_back(make_pair(i,j));
        //             }
        //         }

        //         for(pair<int,int> p:coor){
        //             for(int j=0;j<n;++j) matrix[p.first][j] = 0;
        //             for(int i =0;i<m;++i) matrix[i][p.second] = 0;
        //         }

        // option 2 O(1) space
        // 1. 先將i=0 或 j=0 位置的零點偵測出來
        // 2. 將剩餘i!=0 , j!=0 的零點 對應到該行之首及該列之首設０
        // 3. 將步驟2 設為零的那些點，將該行及該列通通設為０
        // 4. 如果步驟一有偵測出零點，將該行或該列也設為0

        int m = matrix.size(), n = matrix[0].size();
        bool rowHasZero = false;
        bool colHasZero = false;
        // Check if first row has a zero

        for (int j = 0; j < n; ++j)
        {
            if (matrix[0][j] == 0)
            {
                rowHasZero = true;
                break;
            }
        }
        // Check if first col has a zero
        for (int i = 0; i < m; ++i)
        {
            if (matrix[i][0] == 0)
            {
                colHasZero = true;
                break;
            }
        }

        // Check for zeros in the rest of the array
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; ++i)
        {
            if (matrix[i][0] == 0)
            {
                for (int j = 1; j < n; ++j)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 1; j < n; ++j)
        {
            if (matrix[0][j] == 0)
            {
                for (int i = 1; i < m; ++i)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (rowHasZero)
        {
            for (int j = 0; j < n; ++j)
                matrix[0][j] = 0;
        }
        if (colHasZero)
        {
            for (int i = 0; i < m; ++i)
                matrix[i][0] = 0;
        }
    }
};