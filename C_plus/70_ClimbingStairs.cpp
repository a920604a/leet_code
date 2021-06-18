class Solution
{
public:
    int climbStairs(int n)
    {
        // option 1 recurrent, time out O(2^n)
        // if(n <=3) return n;
        // else return climbStairs(n-1) + climbStairs(n-2);

        // option 2 for-loop
        // if(n<=3) return n;
        // int a = 1, b=2;
        // int c = a+b;
        // for(int i=4;i<=n;++i){
        //     a = b;
        //     b = c;
        //     c =a+b;
        // }
        // return c;

        // option 3 dp
        vector<int> dp(n + 1, 1);
        if (n <= 2)
            return n;
        for (int i = 2; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};