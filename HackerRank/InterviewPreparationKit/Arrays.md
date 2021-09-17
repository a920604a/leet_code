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

```python
def hourglassSum(arr):
    # Write your code here
    ret = -9*7
    for i in range(1,5):
        for j in range(1,5):
            ret = max(ret ,
                    arr[i-1][j-1] + arr[i-1][j] + arr[i-1][j+1] +
                                    arr[i][j] + 
                    arr[i+1][j-1] + arr[i+1][j] + arr[i+1][j+1]
                )
        
    return ret
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

```python
def rotLeft(a, d):
    # Write your code here
    s = d%len(a)
    arr = []
    for i in range(len(a)):
        arr.append(a[s])
        s+=1
        s%=len(a)
    return arr

# option 
def rotLeft(a, d):
    # Write your code here
    arr = []
    temp = a[:d]
    temp = temp[::-1]
    arr.extend(temp)
    temp = a[d:]
    temp = temp[::-1]
    arr.extend(temp)
    return arr[::-1]
```
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

```python
def arrayManipulation(n, queries):
    # Write your code here
    prefix = [0 for i in range(n)]
    # 0      0   0   0   0   
    # 100   0   -100
    # 100   100 -100 0  0
    # 100   100 0   0   -100
    
    # 100   200 200 200 100  
    
    for (s,e,val) in queries:
        prefix[s-1] += val
        if e< n:
             prefix[e] -= val
        
    ans = prefix[0]
    item = 0
    for i in range(0, n):
        item += prefix[i]
        ans = max(ans, item)
    return ans

```



# Fail
## Minimum Swaps 2

```python
def minimumSwaps(arr):
    n = len(arr)
    # arr => [1,n]
    temp = [0] * (len(arr) + 1)
    #       4   3   1   2
    #   0   2   3   1   0
    # arr's (idx, val)  => temp (val, idx)
    
    for pos, val in enumerate(arr):
        temp[val] = pos
    
    swaps = 0
    for i in range(len(arr)):
        if arr[i] != i+1:
            # swap
            swaps +=1
            t = arr[i]
            arr[i] = i+1
            arr[temp[i+1]] = t
            temp[t] = temp[i+1]      
    return swaps

```
## New Year Chaos

