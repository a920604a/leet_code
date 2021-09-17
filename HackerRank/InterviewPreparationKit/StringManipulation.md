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


```python
def alternatingCharacters(s):
    # Write your code here
    if len(s) ==1:
        return 0
    
    ret = 0
    prev = s[0]
    for cur in s[1:]:
        if prev==cur:
            ret+=1
        else:
            prev = cur
    return ret
```
## Strings: Making Anagrams


```python
def makeAnagram(a, b):
    # Write your code here
    ret = 0
    ma, mb = defaultdict(int), defaultdict(int)
    s = set()
    for c in a:
        ma[c]+=1
        s.add(c)
    for c in b:
        mb[c]+=1
        s.add(c)
    
    for c in s:        
        if ma[c] == mb[c]:
            continue
        elif ma[c]!=0 and mb[c]!=0:
            ret += abs(mb[c]-ma[c])
        elif ma[c]>0 and mb[c]==0:
            ret += ma[c]
        elif mb[c]>0 and ma[c]==0:
            ret += mb[c]
            
    return ret

#  option 2
freq = [0 for _ in range(26)]
    for c in a:
        freq[ ord(c) - 97] +=1
    for c in b:
        freq[ ord(c) - 97] -=1
        
    for i in range(26):
        ret += abs(freq[i])
    return ret
```


