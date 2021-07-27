class Solution
{
public:
    void solve(vector<vector<char> > &board)
    {
        // 先從周圍做DFS搜尋將O用別的符號代替，因為這些不受影響，最後再還原
        // 剩下的O代表 沒有與四周相連接的，全部改成X
        // 還原步驟1的O
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

//option 2 union find
class UF
{
private:
    int count;
    vector<int> parent;
    vector<int> size;

public:
    UF(int n)
    {
        count = n;
        parent = vector<int>(n);
        size = vector<int>(n);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    void unionSet(int p, int q)
    {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)
            return;

        if (size[rootP] > size[rootQ])
        {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        else
        {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        count--;
    }
    // 判斷p q 是否互相連通
    bool connected(int p, int q)
    {
        int rootP = find(p);
        int rootQ = find(q);
        return rootQ == rootP;
    }
    // 返回 節點 x 的根節點
    int find(int x)
    {
        while (parent[x] != x)
        {
            // 進行路徑壓縮
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    int length()
    {
        return count;
    }
};
class Solution
{
public:
    void solve(vector<vector<char> > &board)
    {
        if (board.size() == 0)
            return;

        int m = board.size(), n = board[0].size();

        UF *uf = new UF(m * n + 1);
        int dummy = m * n;

        // 首行與末行的O與dummy 連通
        for (int i = 0; i < m; ++i)
        {
            if (board[i][0] == 'O')
                uf->unionSet(i * n, dummy);
            if (board[i][n - 1] == 'O')
                uf->unionSet(i * n + n - 1, dummy);
        }

        // 首列與末列的O與dummy 連通
        for (int j = 0; j < n; ++j)
        {
            if (board[0][j] == 'O')
                uf->unionSet(j, dummy);
            if (board[m - 1][j] == 'O')
                uf->unionSet(n * (m - 1) + j, dummy);
        }

        vector<vector<int> > action = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        for (int i = 1; i < m - 1; ++i)
        {
            for (int j = 1; j < n - 1; ++j)
            {
                if (board[i][j] == 'O')
                {
                    // 将此 O 与上下左右的 O 连通
                    for (int k = 0; k < 4; ++k)
                    {
                        int x = i + action[k][0];
                        int y = j + action[k][1];
                        if (board[x][y] == 'O')
                            uf->unionSet(x * n + y, i * n + j);
                    }
                }
            }
        }
        // 所有不和 dummy 连通的 O，都要被替换
        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (!uf->connected(dummy, i * n + j))
                    board[i][j] = 'X';
            }
        }
    }
};