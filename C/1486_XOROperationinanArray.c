

int xorOperation(int n, int start)
{

    int ret = start;
    int a = start + 2;
    for (int i = 1; i < n; ++i)
    {
        ret ^= a;
        a += 2;
    }
    return ret;
}