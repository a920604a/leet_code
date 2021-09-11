

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int count(int n){
    int ret =0;
    while(n){
        ret++;
        n &= n-1;
    }
    return ret;
}
int* countBits(int n, int* returnSize){
    // O(nlogn) time 
    *returnSize = n+1;
    int *ret = calloc(n+1, sizeof(int));
    for(int i=0;i<=n;++i) *(ret+i) = count(i);
    return ret;
    
    
    
    

}