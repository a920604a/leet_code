
int count(int n)
{
    // count the number of one
    int ret = 0;
    while (n)
    {
        ret++;
        n &= n - 1;
    }
    return ret;
}
bool isPrime(int n)
{
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    for (int i = 0; i < 10; ++i)
    {
        if (n == primes[i])
            return true;
    }
    return false;
}
int countPrimeSetBits(int left, int right)
{
    int ret = 0;

    for (int i = left; i <= right; ++i)
    {
        int p = count(i);
        if (isPrime(p))
            ret++;
    }
    return ret;
}