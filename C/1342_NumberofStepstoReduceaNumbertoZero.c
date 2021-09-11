

int numberOfSteps(int num)
{

    // base case
    //     if(num==0) return 0;

    //     if(num%2==0) return numberOfSteps(num/2)+1;
    //     else return numberOfSteps(num-1)+1;

    // bit manipulation
    // 1000 => 4
    // 1110 => 6
    // 遇到1 +2 遇到0 +1 ，最後減一
    int ret = 0;
    if (!num)
        return 0;
    while (num)
    {
        ret += (num & 1 ? 2 : 1);
        num >>= 1;
    }
    return ret - 1;
}