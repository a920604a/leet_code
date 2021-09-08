class Solution
{
public:
    vector<vector<int> > updateMatrix(vector<vector<int> > &mat)
    {

        // option 1 BFS
        int n = mat.size(), m = mat[0].size();
        vector<vector<int> > ret = mat;
        queue<pair<int, int> > q;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (ret[i][j] == 0)
                    q.push({i, j});
                else
                    ret[i][j] = -1;
            }
        }

        vector<vector<int> > dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        while (!q.empty())
        {
            auto t = q.front();
            q.pop();
            cout << t.first << " " << t.second << endl;
            for (auto dir : dirs)
            {
                int x = t.first + dir[0], y = t.second + dir[1];
                if (x < 0 || x > n - 1 || y < 0 || y > m - 1 || ret[x][y] != -1)
                    continue;
                ret[x][y] = 1 + ret[t.first][t.second];

                q.push({x, y});
            }
        }

        return ret;

        // option 2  dp  + two scan 
    }
};