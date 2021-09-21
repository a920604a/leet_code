

## Hash Tables: Ransom Note


```python
def checkMagazine(magazine, note):
    hist = dict()
    for m in magazine:
        hist[m] = hist.get(m,0) +1
    
    for n in note:
        if hist.get(n,0)==0:
            print("No")
            return 
        hist[n]-=1
        
    print("Yes")
```

## Two Strings

```python
def twoStrings(s1, s2):
    # Write your code here
    s = set()
    for c in s1:
        s.add(c)
    for c in s2:
        if c in s:
            return "YES"
    return "NO"
            
```
```python
def twoStrings(s1, s2):
    his = [0 for _ in range(26)]
    for c in s1:
        his[ord(c)-ord('a')] +=1    
    for c in s2:
        if his[ord(c)-ord('a')] > 1:
            return "YES"        
    return "NO"
```

## Frequency Queries

```python
from collections import defaultdict
def freqQuery(queries):
    ret = list()
    num2freq = dict()
    freq2count = defaultdict(int)
    for q in queries:
        if q[0] ==1:
            if num2freq.get(q[1], 0)==0:
                num2freq[q[1]] = 1
                freq2count[1]+=1
            else:
                f = num2freq[q[1]]
                freq2count[f]-=1
                freq2count[f+1]+=1
                num2freq[q[1]]+=1
        elif q[0] ==2:
            f = num2freq.get(q[1], 0)
            if  f==0:
                continue
            num2freq[q[1]]-=1
            freq2count[f]-=1
            if f-1>0: 
                freq2count[f-1]+=1
            
        elif q[0]==3:
            if freq2count[q[1]]:
                ret.append(1)
            else:
                ret.append(0)
            
    return ret
    
   

```

# Fail
## Count Triplets

```python 
# option time out here
def countTriplets(arr, r):
    ret = 0
    for i in range(len(arr)-2):
        for j in range(i+1,len(arr)-1):
            for k in range(j+1, len(arr)):
                if(arr[i] * r == arr[j] and arr[j] *r == arr[k]): 
                    ret+=1           
    return ret

```
```python
def countTriplets(arr, r):
    count = 0
    hist = {}
    histPairs = {}
    #   1   4   16  64
    #   64  16  4   1
    #   hist        histPairs
    #64  {64:1}     {}
    #16  {64:1,16:1}     {16:1}
    #4  {64:1,16:1,4:1} {16:1,4:1}      count = 1
    #1  {64:1,16:1,4:1,1:1}     {16:1,4:1,1:1}      count = 2
    for a in reversed(arr):
        if a*r in histPairs:
            count+=histPairs[a*r]
        if a*r in hist:
            histPairs[a]  = histPairs.get(a,0) + hist[a*r]
        hist[a] = hist.get(a, 0) +1
        print(hist)
        print(histPairs)
    
    return count
```