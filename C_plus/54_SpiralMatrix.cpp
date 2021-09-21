class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> paths;
        vector<vector<bool> > used(n, vector<bool>(m, false));
        vector<int> acts = {0, 1, 0, -1};
        // {0,1} {1,0} {0,-1} {-1,0}
        int p = n * m, a = 0;
        int i = 0, j = -1;
        int pre_x = 0, pre_y = 0;
        int x = 0, y = 0;
        while (p)
        {
            x = i + acts[a % 4], y = j + acts[(a + 1) % 4];
            // cout<<x<<" "<<y<<endl;
            while (x > n - 1 || y > m - 1 || x < 0 || y < 0 || used[x][y] == true)
            {
                a++;
                x = i + acts[a % 4];
                y = j + acts[(a + 1) % 4];
                // cout<<"the corner\t, reannge:\t"<<x<<" "<<y<<endl;
            }
            if (!used[x][y])
            {
                paths.push_back(matrix[x][y]);
                // cout<<"visited:\t"<<x<<" "<<y<<endl;
                used[x][y] = true;
                i = x;
                j = y;
                p--;
            }
        }
        return paths;
    }
};