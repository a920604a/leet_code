class Solution
{
public:
    int helper(vector<int> &memo, int n)
    {
        //base case
        if (n == 0 || n == 1)
            return n;
        if (memo[n] != 0)
            return memo[n];
        memo[n] = helper(memo, n - 1) + helper(memo, n - 2);
        return memo[n];
    }
    int fib(int n)
    {
        //  0   1   1   2   3   5   8   13

        // option 1 brute force solution recusrive O(n!) time
        // if(n==0 || n==1) return n;
        // return fib(n-1) + fib(n-2);

        // option 2 memo pattern 備忘錄 用 vector 或 hash table 紀錄出現過的避免大量重複運算

        // vector<int> memo(n+1, 0);
        // return helper(memo, n);

        // option 2 dp solution

        // if(n ==0 || n == 1) return n;
        // vector<int> dp(n+1,0);
        // // base case
        // dp[0] = 0;
        // dp[1] = 1;
        // for(int i=2;i<=n;++i){
        //     dp[i] = dp[i-1] + dp[i-2];
        // }
        // return dp[n];

        // option 3 reduce dp by variable

        if (n == 0 || n == 1)
            return n;

        int dp_0 = 0, dp_1 = 1;
        int ans = 0;
        for (int i = 2; i <= n; ++i)
        {
            ans = dp_0 + dp_1;

            // for next iteration update
            dp_0 = dp_1;
            dp_1 = ans;
        }

        return ans;
    }
};