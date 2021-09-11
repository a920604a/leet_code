

int findComplement(int num)
{
    // flip number
    int n = num, i = 0;
    while (n)
    {
        i++;
        n >>= 1;
    }
    int mask = 0;
    while (i)
    {
        mask <<= 1;
        mask += 1;
        i--;
    }
    return num ^ mask;
}