

bool hasAlternatingBits(int n)
{
    int p = (n & 1);
    n >>= 1;
    while (n)
    {
        if ((n & 1) && p == 1)
            return false;
        else if ((n & 1) == 0 && p == 0)
            return false;
        p = (n & 1);
        n >>= 1;
    }
    return true;
}