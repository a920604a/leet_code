
# medium-volume
## Sherlock and the Valid String
```python
def isValid(s):
    # Write your code here
    hist = {}    
    for c in s:
        hist[c] = hist.get(c,0) +1
    mode = sorted(hist.values())
    mode = mode[len(mode)//2]
    first = 1
    for k,v in hist.items():
        if v>mode+1:
            return "NO"
        if abs(v-mode) ==1:
            first -=1
            if first<0:
                return "NO"
    return "YES"
```

## Common Child



```python

def commonChild(s1, s2):
    # Write your code here
    #       H   A   R   R   Y
    #
    #S      0   0   0   0   0
    #A      0   1   1   1   1
    #L      0   1   1   1   1
    #L      0   1   1   1   1
    #Y      0   1   1   1   2
    n,m = len(s1),len(s2)    
    prev, cur = [0] * (m+1), [0] * (m+1)
    for i in range(1, 1+n):        
        for j in range(1,1+m):      
            if s1[i-1] == s2[j-1]:
                cur[j] = 1+ prev[j-1]
            else:
                if cur[j-1] > prev[j]:
                    cur[j] = cur[j-1]
                else:
                    cur[j] = prev[j]
        cur , prev = prev, cur                
    return prev[m]


```

## Maximum Palindromes



## Bear and Steady Gene

## Sherlock and Anagrams

## Highest Value Palindrome

