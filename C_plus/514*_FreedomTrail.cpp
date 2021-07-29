class Solution
{
public:
    unordered_map<char, vector<int> > charToIndex;
    vector<vector<int> > memo;
    int dp(string &ring, int i, string &key, int j)
    {
        // 紀錄圓盤指針在ring[i]，輸入key[j..] 的最少操作次數

        // base case，完成輸入
        if (j == key.size())
            return 0;

        // 查看備忘錄
        if (memo[i][j])
            return memo[i][j];

        int n = ring.size();
        // 做選擇
        int ret = INT_MAX;

        for (int k : charToIndex[key[j]])
        {
            // 撥動指針的次數
            int delta = abs(k - i);
            // 選擇順時針還是逆時針
            delta = min(delta, n - delta);
            // 將指針撥到ring[k]，繼續輸入key[j+1..]
            int subProblem = dp(ring, k, key, j + 1);
            // 選擇整體操作次數最少的
            ret = min(ret, 1 + delta + subProblem);
            // PS: 加一 是因為按動按鈕也算一次操作
        }
        memo[i][j] = ret;
        return ret;
    }
    int findRotateSteps(string ring, string key)
    {
        int m = ring.size();
        int n = key.size();

        memo = vector<vector<int> >(m, vector<int>(n, 0));

        // 紀錄圓環上字符到索引的映射
        for (int i = 0; i < ring.size(); ++i)
        {
            charToIndex[ring[i]].push_back(i);
        }

        // 圓盤指針最初指向十二點鐘方向
        // 從第一個字符開始輸入
        return dp(ring, 0, key, 0);
    }
};