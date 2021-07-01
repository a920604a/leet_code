class Solution
{
public:
    void gameOfLife(vector<vector<int> > &board)
    {

        // 在八相鄰 鄰居

        // 任何活著的區域1
        // 任何活著的區域1，少於兩個鄰居活著，代表人口不足，下個階段會死亡0，像示圖座標 (0,1) (2,0)
        // 任何活著的區域1，超過三個鄰居活著，人口過剩，下個階段會死亡0，像示圖座標
        // 任何活著的區域1，有兩或三個鄰居活著，持續觀察 next generation下個階段也會活著1維持，像示圖座標(1,2)  (2,1) (2,2)
        // 兩或三個鄰居活著 代表6或5個死亡
        //
        // 任何死亡的區域0
        // 任何死亡的區域0，有著剛好三個活著的鄰居，會被生殖 reproduction，像示圖座標(1,0) (3,1) -> 1
        // (0,0) (0,2) (1,1) (3,0) (3,2) -> 0

        // option 1 dp
        //         int m= board.size(), n= board[0].size();
        //         vector<vector<int>> next_state(board.begin(), board.end());
        //         vector<pair<int,int>> action = {{-1,-1},{-1,0},{-1,1},
        //                               {0,-1},{0,1},
        //                               {1,-1},{1,0},{1,1}};
        //         for(int i=0;i<m;++i){
        //             for(int j=0;j<n;++j){
        //                 neighborSearch(board, next_state,i,j, action);
        //             }
        //         }

        //         board = next_state;

        // option 2 in-place
        // 0： 死細胞轉為死細胞
        // 1： 活細胞轉為活細胞
        // 2： 活細胞轉為死細胞
        // 3： 死細胞轉為活細胞

        int m = board.size(), n = board[0].size();
        vector<pair<int, int> > action = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int num_live = 0;
                for (pair<int, int> a : action)
                {
                    int x = i + a.first, y = j + a.second;
                    if (x >= 0 && x < m && y >= 0 && y < n && (board[x][y] == 1 || board[x][y] == 2))
                    {
                        ++num_live;
                    }
                }

                if (board[i][j] && (num_live < 2 || num_live > 3))
                    board[i][j] = 2;
                else if (!board[i][j] && num_live == 3)
                    board[i][j] = 3;
            }
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; j++)
            {
                board[i][j] = board[i][j] % 2;
            }
        }
    }

    void neighborSearch(vector<vector<int> > &board, vector<vector<int> > &dp, int i, int j, vector<pair<int, int> > &action)
    {
        int num_die = 0, num_live = 0;
        int m = board.size(), n = board[0].size();

        for (pair<int, int> a : action)
        {
            int neighbor_x = i + a.first, neighbor_y = j + a.second;
            if (neighbor_x < 0 || neighbor_x > m - 1 || neighbor_y < 0 || neighbor_y > n - 1)
                continue;
            num_die += (board[neighbor_x][neighbor_y] == 0) ? 1 : 0;
            num_live += (board[neighbor_x][neighbor_y] == 1) ? 1 : 0;
        }
        if (board[i][j] == 0)
        {
            if (num_live == 3)
                dp[i][j] = 1;
        }
        else if (board[i][j] == 1)
        {
            if (num_live < 2)
                dp[i][j] = 0;
            else if (num_live > 3)
                dp[i][j] = 0;
            // else if(num_live==2 || num_die==3) continue; // dp[i][j] = 1;
        }
    }
};