class Solution
{
public:
    bool helper(vector<vector<char> > &board, int i, int j, vector<vector<bool> > &visited)
    {
        if (i < 0 || j < 0 || i > board.size() - 1 || j > board[0].size() - 1)
            return false;
        if (visited[i][j] || board[i][j] == 'X')
            return board[i][j] == 'X';
        visited[i][j] = true;
        if (helper(board, i - 1, j, visited) || helper(board, i, j - 1, visited) ||
            helper(board, i + 1, j, visited) || helper(board, i, j + 1, visited))
        {
            board[i][j] = 'X';
        }
        return board[i][j] == 'X';
    }
    void solve(vector<vector<char> > &board)
    {

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if ((i == 0 || i == board.size() - 1 || j == 0 || j == board[i].size() - 1) && board[i][j] == 'O')
                    solveDFS(board, i, j);
            }
        }
        for (auto str : board)
        {
            for (char c : str)
                cout << c << " ";
            cout << endl;
        }

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == '$')
                    board[i][j] = 'O';
            }
        }
        for (auto str : board)
        {
            for (char c : str)
                cout << c << " ";
            cout << endl;
        }
    }
    void solveDFS(vector<vector<char> > &board, int i, int j)
    {
        if (board[i][j] == 'O')
        {
            board[i][j] = '$';
            if (i > 0 && board[i - 1][j] == 'O')
                solveDFS(board, i - 1, j);
            if (j < board[i].size() - 1 && board[i][j + 1] == 'O')
                solveDFS(board, i, j + 1);
            if (i < board.size() - 1 && board[i + 1][j] == 'O')
                solveDFS(board, i + 1, j);
            if (j > 0 && board[i][j - 1] == 'O')
                solveDFS(board, i, j - 1);
        }
    }
};