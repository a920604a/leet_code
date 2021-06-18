class Solution
{
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        // O(n*m)
        //check each row
        for (int i = 0; i < board.size(); ++i)
        {
            set<char> s;
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] == '.')
                    continue;
                if (s.find(board[i][j]) != s.end())
                    return false;
                s.insert(board[i][j]);
            }
        }
        // check each column
        for (int i = 0; i < board[0].size(); ++i)
        {
            set<char> s;
            for (int j = 0; j < board.size(); ++j)
            {
                if (board[j][i] == '.')
                    continue;
                if (s.find(board[j][i]) != s.end())
                    return false;
                s.insert(board[j][i]);
            }
        }
        // check sub-boxes (i,j) , k
        // i= 0~2 , j=0~2 , 0
        // i= 0~2 , j=3~5 , 1
        // i=0~2 , j=6~8 , 2
        // i=3~5 , j=0~2, 3
        // i=3~5 , j=3~5, 4
        // i=3~5 , j=6~8, 5
        // i=6~8 , j=0~2 , 6
        // i=6~8 , j=3~5 , 7
        // i=6~8 , j=6~8 , 8

        for (int k = 0; k < 9; ++k)
        {

            int x = k / 3 * 3;
            int y = k % 3 * 3;
            set<char> s;
            cout << k << endl;
            while (x < k / 3 * 3 + 3 && y < k % 3 * 3 + 3)
            { // each sub-box
                if (s.find(board[x][y]) != s.end() && board[x][y] != '.')
                    return false;
                else if (board[x][y] != '.')
                    s.insert(board[x][y]);

                if (y == k % 3 * 3 + 2)
                {
                    y = k % 3 * 3;
                    x++;
                }
                else
                    y++;
            }
        }
        return true;
    }
};