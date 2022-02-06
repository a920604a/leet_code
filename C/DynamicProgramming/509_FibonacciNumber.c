

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n < 3)
        return 1;
    int a = 1, b = 1, c = a + b;
    for (int i = 3; i <= n; ++i)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}