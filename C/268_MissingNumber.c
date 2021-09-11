

int missingNumber(int *nums, int numsSize)
{
    // maybe overflow
    // int total = (numsSize+1)*numsSize/2;
    // for(int i=0;i<numsSize ;++i) total -= *(nums+i);
    // return total;

    int ret = numsSize;
    for (int i = 0; i < numsSize; ++i)
        ret ^= i ^ *(nums + i);
    return ret;
}