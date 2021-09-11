#define max(a, b) ((a > b) ? a : b)

int binaryGap(int n)
{
    int ret = 0, pre = 0;
    int i = 31;
    while ((n >> i) != 1)
        i--;
    pre = i;
    i--;
    while (i > -1)
    {
        if ((n >> i) & 1)
        {
            ret = max(ret, pre - i);
            pre = i;
        }
        i--;
    }
    return ret;

    
}