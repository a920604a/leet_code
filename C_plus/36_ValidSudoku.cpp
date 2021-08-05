class Solution
{
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {

        int m = board.size(), n = board[0].size();

        for (int i = 0; i < n; ++i)
        {
            set<char> s;
            for (int j = 0; j < m; ++j)
            {
                if (board[i][j] != '.')
                {
                    if (s.find(board[i][j]) != s.end())
                        return false;
                    s.insert(board[i][j]);
                }
            }
        }

        for (int j = 0; j < m; ++j)
        {
            set<char> s;
            for (int i = 0; i < n; ++i)
            {
                if (board[i][j] != '.')
                {
                    if (s.find(board[i][j]) != s.end())
                        return false;
                    s.insert(board[i][j]);
                }
            }
        }

        vector<pair<int, int> > coor = {
            {0, 0},
            {0, 1},
            {0, 2},
            {1, 0},
            {1, 1},
            {1, 2},
            {2, 0},
            {2, 1},
            {2, 2},
        };
        for (int i = 0; i < m; i += 3)
        {

            for (int j = 0; j < n; j += 3)
            {
                set<char> s;
                for (pair<int, int> p : coor)
                {
                    int x = p.first + i;
                    int y = p.second + j;
                    if (board[x][y] != '.')
                    {
                        if (s.find(board[x][y]) != s.end())
                            return false;
                        s.insert(board[x][y]);
                    }
                }
            }
        }
        return true;
    }
};