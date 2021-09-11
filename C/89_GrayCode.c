

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// int pow(int a, int n){
//     if(n==1) return a;
//     return a*pow(n-1,a);
// }
int* grayCode(int n, int* returnSize){
    // n = 1, 00, 01
    // n = 2, 00, 01, 11, 10
    // n = 3, 000, 001, 011, 010, 110, 111, 101, 100
    // 後半段為前半段的最高位加一
    
    *returnSize = pow(2,n);
    int *ret = calloc(*returnSize, sizeof(int));
    ret[0] = 0, ret[1] = 1;
    for(int i=2;i<=n;++i){
        int k = 1;
        for(int j=pow(2,i-1) ;j< pow(2,i); ++j){
            ret[j] = ret[j - k] | (1<<(i-1)) ;
            k+=2;
        }   
    }
    return ret;

    // option 2 bit manipulation
    // n = 1, 00 01
    // n = 2, 00(00) 01(00) 11(10) 10(10)
    // n = 3, 000, 001, 011, 010, 110, 111, 101, 100
    *returnSize = pow(2,n);
    int *ret = calloc(*returnSize, sizeof(int));
    for(int i=0;i<(1<<n);i++){
        ret[i] = i^(i>>1);
    }
    return ret;
    
}