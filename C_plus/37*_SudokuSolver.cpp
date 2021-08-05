class Solution
{
public:
    bool isValid(vector<vector<char> > &board, int r, int c, char n)
    {

        for (int i = 0; i < 9; ++i)
        {

            if (board[r][i] == n)
                return false;
            if (board[i][c] == n)
                return false;
            if (board[(r / 3) * 3 + i / 3][(c / 3) * 3 + i % 3] == n)
                return false;
        }
        return true;
    }
    bool traverse(vector<vector<char> > &board, int r, int c)
    {
        int m = 9, n = 9;
        if (c == n)
        {
            return traverse(board, r + 1, 0);
        }
        if (r == m)
            return true;

        if (board[r][c] != '.')
        {
            return traverse(board, r, c + 1);
        }
        for (char ch = '1'; ch <= '9'; ++ch)
        {

            if (!isValid(board, r, c, ch))
                continue;

            board[r][c] = ch;
            if (traverse(board, r, c + 1))
                return true;
            board[r][c] = '.';
        }
        return false;
    }
    void solveSudoku(vector<vector<char> > &board)
    {

        if (traverse(board, 0, 0))
            return;
    }
};