
## The Coin Change Problem

```python
def getWays(amount, c):
    # Write your code here
    #   0   1   2   3
    #   1   0   0   0
    #   1   1   0   0
    #   1   1   2   0
    #   1   1   2   3   

    n = len(c)
    dp = [0 for _ in range(amount+1)]
    dp[0] = 1
    for i in range(1, n+1):
        for j in range(1, amount+1):
            if j >= c[i-1]:
                dp[j] = dp[j] + dp[j-c[i-1]]
    return dp[amount]
```


## Fibonacci Modified

```python
def fibonacciModified(t1, t2, n):
    # Write your code here
    #   0   1   5
    
    #   0   1   1   2   5   27
    # n=3 => 1
    # n=4 => 2
    # n=5 => 5
    if n==1:
         return t1
    if n==2:
        return t2
    a, b ,c= t1, t2, t1 + t2*t2
    for i in range(2,n):
        c = a + b*b
        a = b
        b = c
    return c

```


## The Maximum Subarray

```python

def maxSubarray(arr):
    #   1   2   3   4
    #  subarray
    #  subsequence pick positive numvber and sum
    #  
    local_max, global_max = 0, -10000
    subseq, mn = 0,-10000
    for a in arr:
        if a>0:
            subseq+=a
        if a<0:
            mn = max(a, mn)
        local_max = max(a, a+local_max)
        global_max = max(local_max, global_max)
    if subseq==0:
        subseq = mn
    return global_max, subseq

```


## Xor and Sum


```python
def xorAndSum(a, b):
    # Write your code here
    x=int(a,2)
    y=int(b,2)
    p=0
    for i in range(0,314160):
        p+=x^(y<<i)
    return p%((10**9)+7)
```

# Fail
## Sherlock and Cost


```python 
def cost(arr):
    #B      1   2   3
    #A = 6 kind, and max is  2 and that occur (1,2,1) , (1,1,3) ,(1,2,3)
    
    #   1   2   3   4   
    #  A = 24 kind, and max is 5 and that occur (1,1,3,1) (1,2,1,4)
    
    #       2   4   3
    # assume A corner case has below two
    #       1   1   1
    #       2   4   3
    #dp[i][0] means  the max sum of A[0~i] when A[i]=1
    #dp[i][1] means  the max sum of A[0~i] when A[i]=B[i] 
    #       0   1   6
    #       0   3   4
    
    
    #       1   1   1   1   1
    #       100 2   100 2   100
    #       0   99  99
    #       0   98  
    L=len(B)
    dp=matrix = [[0 for i in range(2)] for i in range(L)]
    i=1
    while i<len(B):
        dp[i][0]=max(dp[i-1][0], dp[i-1][1]+B[i-1]-1)
        dp[i][1]=max(dp[i-1][0]+B[i]-1, dp[i-1][1]+abs(B[i]-B[i-1]))
        i += 1
    print(dp)
    return max(dp[L-1][0],dp[L-1][1])

```


## Sam and substrings
get all subarray and sum

```python
```