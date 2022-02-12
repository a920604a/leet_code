
int reverse(int x)
{
    int rever = 0;
    int num = x;
    while (x > 0)
    {
        rever = rever * 10 + (x % 10);
        x /= 10;
    }
    return rever;
}
bool isSameAfterReversals(int num)
{
    if (num == 0)
        return true;
    return num == reverse(reverse(num));
}