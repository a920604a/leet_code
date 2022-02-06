

int climbStairs(int n)
{
    //  1   2   3   5
    if (n < 3)
        return n;
    int a = 1, b = 2, c = a + b;
    for (int i = 3; i <= n; ++i)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}