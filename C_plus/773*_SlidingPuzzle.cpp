class Solution
{
public:
    int slidingPuzzle(vector<vector<int> > &board)
    {
        // [[1,2,3],[4,0,5] ]  = 1 2 3 4 0 5
        int m = 2, n = 3;
        string start = "";
        string target = "123450";
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                start.push_back(board[i][j] + '0');
            }
        }
        // start = [1,2,3,4,0,5]
        // 紀錄每個index 鄰居的index
        vector<vector<int> > neighbor = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};

        // BFS
        queue<string> q;
        unordered_set<string> visited;
        q.push(start);
        visited.insert(start);
        int step = 0;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                string cur = q.front();
                q.pop();

                if (target == cur)
                    return step;

                int idx = 0;
                // 找數字０的索引
                for (; cur[idx] != '0'; ++idx)
                    ;
                for (int adj : neighbor[idx])
                {
                    string new_board = cur;

                    swap(new_board[adj], new_board[idx]);
                    if (!visited.count(new_board))
                    {
                        q.push(new_board);
                        visited.insert(new_board);
                    }
                }
            }
            step++;
        }

        return -1;
    }
};