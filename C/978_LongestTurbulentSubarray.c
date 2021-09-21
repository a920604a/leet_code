#define max(a,b) ((a>b)?a:b)

int maxTurbulenceSize(int* arr, int arrSize){
    
    //r1 arr[0] < arr[1] arr[1] > arr[2]
    //r2 arr[0] > arr[1] arr[1] < arr[2]
    // two dp
    //      9   4   2   10  7   8   8   1   9
    //r1    1   1   2   3   4   5   1   1   1  
    //r2    1   2   1   1   1   1   1   2   3      
    
    int *r1 = calloc(arrSize, sizeof(int)), *r2 = calloc(arrSize, sizeof(int));
    r1[0] = 1, r2[0] = 1;
    int ret = 1;
    for(int i=1;i<arrSize ;++i){
        if(i %2==0){
            if(arr[i] < arr[i-1]) r1[i] = 1+ r1[i-1];
            else r1[i] = 1;
            
            if(arr[i] > arr[i-1]) r2[i] = 1+ r2[i-1];
            else r2[i] = 1;
        }
        else{
            if(arr[i] > arr[i-1]) r1[i] = 1+ r1[i-1];
            else r1[i] = 1;
            
            if(arr[i] < arr[i-1]) r2[i] = 1+ r2[i-1];
            else r2[i] = 1;
        }
        ret = max(r1[i], ret);
        ret = max(r2[i], ret);
        printf("%d\t%d\n", r1[i],r2[i]);
    }
    return ret;

}