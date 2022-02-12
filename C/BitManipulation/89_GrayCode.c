

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize){
    *returnSize = 1<<n;
    int *ret = calloc( *returnSize, sizeof(int));
    for(int i=0;i<*returnSize;++i){
        ret[i] = (i>>1)^i;
    }
    return ret;

}