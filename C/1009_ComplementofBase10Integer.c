

int bitwiseComplement(int n)
{
    // option 1
    // unsigned mask = ~0;
    // if(n==0) return 1;
    // int i=31;
    // while((n>>i)==0) i--;
    // mask = mask<<(i+1);
    // mask = ~mask;
    // return n ^ mask;

    // option 1
    if (n == 0)
        return 1;
    int num = n;
    int i = 0;
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