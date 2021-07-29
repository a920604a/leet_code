class Solution
{
public:
    unordered_map<int, list<vector<int> > > indegree;
    vector<vector<int> > memo;
    int src, dst;
    int dp(int s, int k)
    {
        // 定義:從s出發，k步類到達s的最小成本
        if (s == src)
            return 0;
        // 步數用盡
        if (k == 0)
            return -1;
        int ret = INT_MAX;

        // 查看備忘錄
        if (memo[s][k] != -888)
            return memo[s][k];

        if (indegree.count(s))
        {

            for (auto v : indegree[s])
            {
                int from = v[0];
                int price = v[1];

                int subProblem = dp(from, k - 1);
                if (subProblem != -1)
                {
                    ret = min(ret, subProblem + price);
                }
            }
        }
        memo[s][k] = ret == INT_MAX ? -1 : ret;
        return memo[s][k];
    }
    int findCheapestPrice(int n, vector<vector<int> > &flights, int src, int dst, int k)
    {

        this->src = src;
        this->dst = dst;
        k++;
        // 初始備忘錄
        memo = vector<vector<int> >(n, vector<int>(k + 1, -888));

        for (vector<int> f : flights)
        {
            int from = f[0];
            int to = f[1];
            int price = f[2];

            indegree[to].push_back({from, price});
        }

        return dp(dst, k);
    }
};