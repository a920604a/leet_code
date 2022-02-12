#define min(a, b) ((a < b) ? a : b)

int minCostClimbingStairs(int *cost, int costSize)
{
    //  10  15  20
    //  0   0   10  15

    //  1   100 1   1   1   100 1   1   100 1
    //  0   0   1   2   2   3   3   4   4   5   6

    // int *dp = calloc( 1 + costSize, sizeof(int));
    // dp[0]= 0;
    // dp[1] = 0;
    // for(int i=2;i<=costSize ;++i){
    //     dp[i] = min(dp[i-2]+cost[i-2], dp[i-1]+cost[i-1]);
    // }
    // return dp[costSize];

    int a = 0, b = 0, c = 0;
    for (int i = 2; i <= costSize; ++i)
    {
        c = min(cost[i - 2] + a, cost[i - 1] + b);
        a = b;
        b = c;
    }
    return c;
}