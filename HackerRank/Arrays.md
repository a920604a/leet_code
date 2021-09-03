## 2D Array - DS
```cpp
int hourglassSum(vector<vector<int>> arr) {
    int ret = INT_MIN;
    for(int i=1 ; i<5;++i){
        for(int j=1;j<5 ;++j){
            int temp = arr[i-1][j-1] + arr[i-1][j] + arr[i-1][j+1] +\
                                        arr[i][j] + \
                        arr[i+1][j-1] + arr[i+1][j] + arr[i+1][j+1];
                        
            ret = max(ret, temp);          
        }
    }
    return ret;
}
```

## Arrays: Left Rotation
```cpp
vector<int> rotLeft(vector<int> a, int d) {
    int n = a.size();
    d = d%n;
    vector<int> ret(n,0);
    for(int i=0;i<n ;++i) {
        ret[i] = a[(d+i)%n];
    }
    return ret;
}
// option 2
vector<int> rotLeft(vector<int> a, int d) {
    
    int n = a.size();
    d = d%n;
    reverse(a.begin(), a.begin() +d);
    reverse(a.begin()+d, a.end());
    reverse(a.begin(), a.end());
    return a;
} 

```



## Minimum Swaps 2


## Array Manipulation
```cpp
long arrayManipulation(int n, vector<vector<int>> queries) {
    // [1,2,100],[2,5,100],[3,4,100]
    //  0   0   0   0   0   0
    //  100 0 -100 
    //  100 100 -100 0  0  
    //diff 100 100 0  0 -100 
    //ret  100  200 200 200 100
    //  100 200 200 200 100
    
    vector<int> diff(n,0);
    for(vector<int> q :queries){
        int i = q[0]-1, j = q[1]-1, val = q[2];
        diff[i]+=val;
        if(j+1 <diff.size()) diff[j+1] -=val;
    }
    
    long long ans = (long long)diff[0];
    long long itt = 0;
    for(int i=0 ; i<n;++i){
        itt+=diff[i];
        ans = max(ans, itt);
    }    
    
    return ans;
    
}
```
