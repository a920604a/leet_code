
## Pairs

```python
def pairs(k, arr):
    # two pinter
    arr.sort()
    ret = 0
    i,j = 0,0
    #       1   2   3   4   5
    while j<len(arr):
        if arr[j]-arr[i] < k:
            j+=1
        elif arr[j] -arr[i] ==k:
            ret+=1
            j+=1
        elif arr[j] - arr[i] > k:
            i+=1
    return ret
```

## Connected Cells in a Grid


```python
def dfs(matrix, i, j):
    n,m = len(matrix), len(matrix[0])
    if i<0 or i>n-1 or j<0 or j>m-1 or matrix[i][j]==0:
        return 0
    ret = 1
    matrix[i][j] = 0
    ret+=dfs(matrix, i-1, j-1)
    ret+=dfs(matrix, i-1, j)
    ret+=dfs(matrix, i-1, j+1)
    ret+=dfs(matrix, i, j-1)
    ret+=dfs(matrix, i, j+1)
    ret+=dfs(matrix, i+1, j-1)
    ret+=dfs(matrix, i+1, j)
    ret+=dfs(matrix, i+1, j+1)
    return ret
    
def connectedCell(matrix):
    # Write your code here
    n,m = len(matrix), len(matrix[0])
    maxarea = 0
    for i in range(n):
        for j in range(m):
            if matrix[i][j] == 0: continue
            area = dfs(matrix, i, j)
            maxarea = max(area, maxarea)
    return maxarea
```



# Fail
## Minimum Loss

```python
def minimumLoss(price):
    #  brute force
    # n = len(price)
    # minPro = max(price)
    # for i in range(0, n-1):
    #     for j in range(i+1, n):
    #         if price[i] - price[j] > 0: 
    #             minPro = min(price[i] - price[j], minPro)
    # return minPro    
    
    nums = list(price)
    nums.sort()
    minCost = 1e+16
    for i in range(1,n):
        if (nums[i]-nums[i-1] < minCost)  and (price.index(nums[i]) < price.index(nums[i-1])):
            minCost = nums[i]-nums[i-1]
    return minCost
```