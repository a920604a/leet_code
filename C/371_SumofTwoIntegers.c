

int getSum(int a, int b)
{
    long long sum = 0, carry = 0;
    long long ret = 0;
    for (int i = 0; i < 32; ++i)
    {
        sum = carry;
        sum += (a & 1) + (b & 1);
        carry = sum / 2;
        sum %= 2;

        ret += sum << i;
        a >>= 1;
        b >>= 1;
    }
    return ret;
}