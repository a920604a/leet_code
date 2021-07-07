class Solution
{
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target)
    {

        // option 1
        // binary search
        if (matrix.empty() || matrix[0].empty())
            return false;

        int l = 0, r = matrix.size();
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] < target)
                l = mid + 1;
            else if (matrix[mid][0] > target)
                r = mid;
        }

        int tmp = (r > 0) ? (r - 1) : r;
        l = 0;
        r = matrix[tmp].size();
        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (matrix[tmp][mid] == target)
                return true;
            else if (matrix[tmp][mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return false;

        // option 2
        // int m = matrix.size(), n= matrix[0].size();
        // int i = m-1, j=0;
        // while( i >=0 && j<=n-1){
        //     if(target ==matrix[i][j]) return true;
        //     if(target > matrix[i][j]) j++;
        //     else i--;
        // }
        // return false;
    }
};