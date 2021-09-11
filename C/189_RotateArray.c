void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void reverse(int *nums, int i, int j)
{
    while (i < j)
    {
        swap(&nums[i++], &nums[j--]);
    }
}
void rotate(int *nums, int numsSize, int k)
{

    // option 1 cheap
    //     int *ret = calloc(numsSize, sizeof(int));
    //     k = numsSize - k%numsSize;
    //     for(int i=0;i<numsSize ; ++i, k++){
    //         ret[i] = nums[k%numsSize];

    //     }
    //     memcpy(nums, ret,numsSize*sizeof(int) );
    //     free(ret);

    // option 1 reverse-base
    k = numsSize - k % numsSize;
    // reverse(nums.begin(), nums.begin()+k);
    // reverse(nums.begin()+k, nums.end());
    // reverse(nums.begin(), nums,end());
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
    reverse(nums, 0, numsSize - 1);
}