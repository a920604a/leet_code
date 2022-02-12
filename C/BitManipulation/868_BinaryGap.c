#define max(a, b) ((a > b) ? a : b)

int binaryGap(int n)
{
    int ret = 0, i = 0, j = 0;
    while ((n & 1) == 0)
    {
        n >>= 1;
        i++;
    }
    j = i;
    while (n)
    {
        if (n & 1)
        {
            ret = max(ret, i - j);
            j = i;
        }
        i++;
        n >>= 1;
    }
    return ret;
}