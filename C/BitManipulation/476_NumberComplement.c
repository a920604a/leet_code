

int findComplement(int num)
{
    int x = num, i = 0;
    while (x)
    {
        i++;
        x >>= 1;
    }
    int mask = 0;
    while (i)
    {
        i--;
        mask <<= 1;
        mask++;
    }

    return num ^ mask;
}