

int numberOfSteps(int num)
{
    // if(num==0) return 0;
    // if((num&1)==0) return 1+numberOfSteps(num/2);
    // else return 1+numberOfSteps(num-1);

    int ret = 0;
    while (num)
    {
        if (num % 2 == 0)
            num >>= 1;
        else
            num--;
        ret++;
    }
    return ret;
}