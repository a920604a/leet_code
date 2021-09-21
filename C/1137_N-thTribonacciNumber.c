

int tribonacci(int n)
{

    //      0   1   1   2   4   7   13  24
    if (n < 2)
        return n;
    if (n == 2)
        return 1;

    int a = 0, b = 1, c = 1, d = 2;
    for (int i = 3; i <= n; ++i)
    {
        d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
    return d;
}