## Max Array Sum


類leetcode Robber
```python

def maxSubsetSum(arr):
    #       3   7   4   6   5
    #       3   7   7   13  13
    
    #       3   5   -7  8   10
    #       3   5   5   13  15
    n = len(arr)
    dp = [0 for x in range(n)]
    dp[0], dp[1] = arr[0], max(arr[1], arr[0])
    for i in range(2,n):
        dp[i] = max(dp[i-2] + arr[i], dp[i-1], arr[i])
        
    return dp[n-1]
```

## Candies
leetcode 135. Candy
```python
def candies(n, arr):
    # Write your code here
    #   4   6   4   5   6   2
    #l  1   2   1   2   3   1
    #r  1   2   1   2   3   1
    
    #   2   4   2   6   1   7   8   9   2   1
    #   1   1   1   1   1   1   1   1   1   1   
    #l  1   2   1   2   1   2   3   4   1   1
    #r  1   2   1   2   1   2   3   4   2   1
    dp_l , dp_r = [1 for i in range(n)], [1 for i in range(n)]
    for i in range(1,n):
        if arr[i]> arr[i-1]:
            dp_l[i] = dp_l[i-1]+1
    for i in range(n-2,-1, -1):
        if arr[i] > arr[i+1]:
            dp_r[i] = 1+dp_r[i+1]
    ret = 0
    for i in range(n):
        ret += max(dp_l[i], dp_r[i])
    return ret
```

## Abbreviation

```python




def abbreviation(a, b):
    #       A   b   c   D   E
    #   t   f   f   f   f   f
    #A  f   t   t   t   f   f
    #B  f   f   t   t   f   f
    #D  f   f   f   f   t   f
    #E  f   f   f   f   f   t

    m, n  = len(a), len(b)
    dp = [[False for i in range(m+1)] for j in range(n+1)]
    dp[0][0] = True
    for i in range(n+1):
        for j in range(m+1):
            if i==0 and j!=0:
                dp[i][j] = a[j-1].islower() and dp[i][j-1]
            elif i!=0 and j!=0:
                if a[j-1] == b[i-1]:
                    # 一樣
                    dp[i][j] = dp[i-1][j-1]
                elif a[j-1].upper() == b[i-1]:
                    # A轉成大小與b一樣
                    dp[i][j] = dp[i-1][j-1] or dp[i][j-1]
                elif not (a[j-1].isupper() and b[i-1].isupper()):
                    # a b 其中一個大寫或都小寫
                    dp[i][j] = dp[i][j-1]
           
                # 其餘狀況，都大寫，預設false
    return "YES" if dp[n][m] else "NO"

```

