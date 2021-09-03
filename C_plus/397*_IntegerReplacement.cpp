class Solution
{
public:
    unordered_map<int, int> memo;
    int integerReplacement(int n)
    {

        // option 1
        //         if(n==1) return 0;
        //         long long t = n;
        //         if(n%2==0)return  1+ integerReplacement(t/2);

        //         // avoid overflow
        //         else return 2+min(integerReplacement((t-1)/2), integerReplacement((t+1)/2));

        // option 1.1 memo pattern to faster
        //         if(n==1) return 0;
        //         if(memo.count(n)) return memo[n];
        //         long long t = n;
        //         if(n%2==0) memo[n] = 1+ integerReplacement(t/2);
        //         // avoid overflow
        //         else memo[n] = 2+min(integerReplacement((t-1)/2), integerReplacement((t+1)/2));
        //         return memo[n];

        // option 2 dp time out
        //  0   1   2   3   4   5   6   7   8
        //  0   0   1   2   2   3   3   4   3
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; ++i)
        {
            if (i % 2 == 0)
                dp[i] = 1 + dp[i / 2];
            else
                dp[i] = 1 + min(dp[(i - 1)], 1 + dp[(i / 2 + 1)]);
        }
        return dp[n];
    }
};