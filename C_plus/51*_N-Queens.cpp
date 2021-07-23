class Solution
{
public:
    void backtrack(vector<string> &board, int row, vector<vector<string> > &ret)
    {
        // 結束條件
        if (row == board.size())
        {
            ret.push_back(board);
            return;
        }
        int n = board[row].size();

        for (int col = 0; col < n; col++)
        {
            // 排除不合法選擇
            if (!isValid(board, row, col))
                continue;
            // 做選擇
            board[row][col] = 'Q';
            // 進入下一列決策
            backtrack(board, row + 1, ret);
            // 撤銷選擇
            board[row][col] = '.';
        }
    }
    bool isValid(vector<string> &board, int row, int col)
    {

        int n = board.size();
        // 檢查是否有皇后衝突
        for (int i = 0; i < n; ++i)
        {
            if (board[i][col] == 'Q')
                return false;
            if (board[row][i] == 'Q')
                return false;
        }
        // 檢查右上方是否有其他皇后
        for (int i = row - 1, j = col + 1;
             i >= 0 && j < n;
             i--, j++)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        // 檢查左上方是否有其他皇后
        for (int i = row - 1, j = col - 1;
             i >= 0 && j >= 0;
             i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    vector<vector<string> > solveNQueens(int n)
    {

        vector<vector<string> > ret;

        vector<string> board(n, string(n, '.'));
        backtrack(board, 0, ret);

        return ret;
    }
};