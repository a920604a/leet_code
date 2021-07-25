class Solution
{
private:
    vector<vector<int> > memo;

public:
    int count(int lo, int hi)
    {
        // 定義：閉區間 [lo, hi] 的數字組成count(lo, hi) 種BST
        if (lo > hi)
            return 1;

        // 查備忘錄
        if (memo[lo][hi] != 0)
        {
            return memo[lo][hi];
        }

        int ret = 0;
        for (int i = lo; i <= hi; ++i)
        {
            int left = count(lo, i - 1);
            int right = count(i + 1, hi);
            // 左右子树的组合数乘積是 BST 的總數
            ret += left * right;
        }
        // 存入備忘錄
        memo[lo][hi] = ret;
        return ret;
    }
    int numTrees(int n)
    {
        // option 1 memo pattern
        memo = vector<vector<int> >(n + 1, vector<int>(n + 1));

        return count(1, n);

        // option 2 math
        // Catalan number
        // 1 1 2 5 14 42 132 429 1430 從０開始
        // (2n)!/((n+1)!* n!)
        // C_{n+1} = \sum{n}{i=0} C_{i}C_{n-i}

        // C_{n} = \sum{n-1}{i=0} C_{i}*C_{n-1-i}
        // n = 1, C_{1} = C_{0}*C_{0} = 1
        // n = 2, C_{2} = C_{0}*C_{1}  + C_{1}*C_{0} = 2
        // n = 3, C_{3} = C_{0}*C_{2}  + C_{1}*C_{1} + C_{2}*C_{0} = 1*2 + 1*1 + 2*1 = 5

        // vector<int> dp(n+1,0);
        // dp[0] = 1;
        // dp[1] = 1;
        // for(int i=2;i<=n;++i){
        //     for(int j = 0;j<i;j++){
        //         dp[i] += dp[j]*dp[i-1-j];
        //     }
        // }
        // return dp[n];
    }
};