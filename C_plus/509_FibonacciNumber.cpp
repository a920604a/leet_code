class Solution
{
public:
    int fib(int n)
    {
        // option 1 O(n!) recursive brute
        // if(n<2) return n;
        // return fib(n-1) + fib(n-2);

        // option 2 O(n) 備忘錄 用 vector 或 hash table 紀錄出現過的避免大量重複運算
        // if(n<1) return 0;
        // vector<int> memo(n+1,0);
        // return helper(n, memo);

        // option 3 dynamic programming
        // if(n<1) return 0;
        // if(n==1 || n==2) return 1;
        // vector<int> dp(n+1,0);
        // // base case
        // dp[1] = dp[2] = 1;
        // for (int i = 3; i <= n; i++)
        //     dp[i] = dp[i - 1] + dp[i - 2];
        // return dp[n];

        // optnio 4 優化dp
        if (n < 1)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        int prev = 1, cur = 1;
        for (int i = 3; i <= n; ++i)
        {
            int sum = prev + cur;
            prev = cur;
            cur = sum;
        }
        return cur;
    }
    int helper(int n, vector<int> &memo)
    {
        if (n == 1 || n == 2)
            return 1;

        if (memo[n] != 0)
            return memo[n];
        memo[n] = helper(n - 1, memo) + helper(n - 2, memo);
        return memo[n];
    }
};