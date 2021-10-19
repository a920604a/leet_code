class Solution
{
public:
    vector<vector<int> > generateMatrix(int n)
    {
        vector<int> acts = {0, 1, 0, -1};
        vector<vector<int> > ret(n, vector<int>(n, 0));
        vector<vector<bool> > used(n, vector<bool>(n, false));
        int i = 0, j = -1, a = 0, p = 1;
        while (p <= n * n)
        {
            int x = i + acts[a % 4];
            int y = j + acts[(a + 1) % 4];

            while (x < 0 || x > n - 1 || y > n - 1 || y < 0 || used[x][y])
            {
                a++;
                x = i + acts[a % 4];
                y = j + acts[(a + 1) % 4];
            }
            ret[x][y] = p++;
            used[x][y] = true;
            i = x;
            j = y;
        }
        return ret;
    }
};