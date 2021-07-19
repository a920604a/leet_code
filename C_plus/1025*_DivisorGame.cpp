class Solution
{
public:
    bool divisorGame(int n)
    {
        // option 1 dp
        vector<bool> dp(n + 1);
        // 起始數字為i，Alice是否會贏
        dp[0] = false;
        dp[1] = false;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j < i; ++j)
            {
                if (i % j != 0)
                    continue;
                if (dp[i - j] == false)
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];

        // option 2 拿到1必輸，拿到2則贏
        // return n%2==0;
    }
};