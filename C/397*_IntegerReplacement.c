

int integerReplacement(int n)
{
    long long t = n;
    int ret = 0;
    while (t > 1)
    {
        if (t % 2 == 0)
            t >>= 1;
        else if ((t + 1) % 4 == 0 && t != 3)
        {
            // 判斷某數加 1 後是 4 的倍數
            t++;
        }
        else
            t--;
        ret++;
    }
    return ret;
}