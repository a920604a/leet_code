

int tribonacci(int n)
{
    //  0   1   1   2   4
    if (n == 0)
        return 0;
    if (n == 2 || n == 1)
        return 1;
    int a = 0, b = 1, c = 1, d = a + b + c;
    for (int i = 3; i <= n; ++i)
    {
        d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
    return d;
}