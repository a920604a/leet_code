## Sherlock and the Valid String


```python 

def isValid(s):
    # Write your code here
    mp = dict()
    mx, mn = 0,10000
    for i in range(len(s)):
        mp[s[i]] = mp.get(s[i],0) +1    
    
    med = sorted(mp.values())
    med = med[len(med)//2]
    f = True
    for (k,v) in mp.items():
        print(k,v)
        if v == med:
            pass
        elif v != med and f:
            if mp[k] -1 == 0:
                f = False
            elif mp[k] -1 == med:
                f = False
            else:
                return "NO"
            
        else:
            return "NO"
    return "YES"
        


```

## Common Child

最長共同子字串


```python
def commonChild(s1, s2):
    # Write your code here
    # LCS
    #       h   a   r   r   y   
    #   0   0   0   0   0   0   
    #s  0   0   0   0   0   0
    #a  0   0   1   1   1   1   
    #l  0   0   1   1   1   1   
    #l  0   0   1   1   1   1
    #y  0   0   1   1   1   2
    # n, m = len(s1), len(s2)
    # dp = [ [0 for x in range(n+1)] for y in range(m+1)]
    
    # for i in range(1, n+1):
    #     for j in range(1, m+1):
    #         if(s1[i-1] == s2[j-1]): dp[i][j] = 1+ dp[i-1][j-1]
    #         else: dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    # return dp[n][m]
    
    # option 2 slove dp
    n, m = len(s1), len(s2)
    prev, cur = [0] * (m+1), [0] * (m+1)
    for i in range(1, n+1):
        for j in range(1, m+1):
            if(s1[i-1] == s2[j-1]): 
                cur[j] = 1+ prev[j-1]
            else:
                # cur[j] = max(prev[j], cur[j-1])
                if cur[j-1] > prev[j]:
                    cur[j] = cur[j-1]
                else:
                    cur[j] = prev[j]
        # print(prev, cur)
        cur , prev = prev, cur
        
    return prev[m]

   
```

## Special String Again

```python

def substrCount(n, s):

    ret = n
    for i,c in enumerate(s):
        diff = None
        for j in range(i+1,n ):
            if s[j] == c:
                if diff is None:
                    ret+=1
                elif diff-j == i-diff:
                    ret+=1
                    break
            else:
                if diff is None:
                    diff = j
                else:
                    break
    return ret

```

## Alternating Characters

紀錄上一個字母，比較當前字母，相同則加一
```python
def alternatingCharacters(s):
    cur = s[0]
    ret = 0
    for a in s[1:]:
        if a==cur:
            ret+=1
        elif a!=cur:
            cur =a
    return ret
```
## Strings: Making Anagrams

直接統計字母出現頻率
```python

def makeAnagram(a, b):
    histA = [0 for i in range(26)]
    histB = [0 for i in range(26)]
    ret = 0 
    for c in a:
        histA[ord(c)-ord('a')]+=1
    for c in b:
        histB[ord(c)-ord('a')]+=1
    for i in range(26):
        ret += abs(histB[i]-histA[i])
    return ret
```


