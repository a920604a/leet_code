class Solution
{
public:
    int minimumTotal(vector<vector<int> > &triangle)
    {
        //    2
        //   3 4
        //  6 5 7
        // 4 1 8 3

        //    2
        //   5 6
        // 11 10 13
        //15 11 18 16

        int size = triangle.size();
        for (int i = 1; i < size; ++i)
        {
            for (int j = 0; j < triangle[i].size(); ++j)
            {
                if (j == 0)
                    triangle[i][j] += triangle[i - 1][j];
                else if (j == triangle[i].size() - 1)
                    triangle[i][j] += triangle[i - 1][j - 1];
                else
                    triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
        }
        int ret = triangle[size - 1].front();
        for (int r : triangle[size - 1])
            ret = min(ret, r);
        return ret;
    }
};