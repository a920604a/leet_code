class Solution
{
public:
    int is_square(int n)
    {
        int sqrt_n = (int)(sqrt(n));
        return (sqrt_n * sqrt_n == n);
    }

    int numSquares(int n)
    {

        // option 1 math
        // Legendre's three-square theorem，任一正整數皆可用 4 個整數的平方和表示。
        // 2 = {1,1,0,0} 的整數平方和。
        //  也可以說 除了 0 返回結果可能 1,2,3,4個的其中一個，也就是說本題答案介於 [1,4] 區間
        // 任何由四個平方和數字組成的數字，皆可表示成 4^k*(8*m + 7).
        // 2 = {1,1}
        // 8 = {2,2}

        //         if(is_square(n))
        //         {
        //             return 1;
        //         }
        //         while (n%4 == 0  ) // ((n & 3) == 0)
        //         {
        //             n >>= 2;
        //         }
        //         if( n%8 == 7) // ((n & 7) == 7)
        //         {
        //             return 4;
        //         }

        //         for (int i = 0; i * i <= n; ++i) {
        //             if (is_square(n - i*i))
        //             {
        //                 return 2;
        //             }
        //         }
        //         return 3;

        // dp
        // dp[i] 表示 正整數 i 能由多少個完全平方數組成
        //
        //      0   1   2   3   4   5   6   7   8   9   10  11  12
        //      +   +   +   +   +   +   +   +   +   +   +   +   +
        //      0
        //i=0   0   1   +   +   1   +   +   +   +   1   +   +   +
        //i=1   0   1   2   +   1   2   +   +   +   1   2   +   +
        //i=2   0   1   2   3   1   2   3   +   +   1   2   3   +
        //i=3   0   1   2   3   1   2   3   4   +   1   2   3   4
        //i=4   0   1   2   3   1   2   3   4   2   1   2   3   4
        //i=5   0   1   2   3   1   2   3   4   2   1   2   3   4
        //i=6   0   1   2   3   1   2   3   4   2   1   2   3   4
        //i=7   0   1   2   3   1   2   3   4   2   1   2   3   4
        //i=8   0   1   2   3   1   2   3   4   2   1   2   3   4
        //i=9   0   1   2   3   1   2   3   4   2   1   2   3   4
        //i=10  0   1   2   3   1   2   3   4   2   1   2   3   4

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= n; ++i)
        {
            for (int j = 1; i + j * j <= n; ++j)
            {
                dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
            }
        }

        return dp[n];
    }
};