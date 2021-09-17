

## Hash Tables: Ransom Note


```python
def checkMagazine(magazine, note):
    # Write your code here
    his = dict()
    for i in magazine:
        if i not in his: 
            his[i] = 1
        else:
            his[i] +=1

    for c in note:
        if c not in his or his[c]==0:
            print("No")
            return
        else:
            his[c]-=1
    
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

## Frequency Queries

```python
def freqQuery(queries):
    ret = list()
    num2freq = dict()
    freq2count = defaultdict(int)
    for (q,val) in queries:
        initial = num2freq.get(val,0)
        if q==1:
            freq2count[ initial] -=1
            num2freq[val] = initial +1
            freq2count[num2freq.get(val,0)  ] +=1
        elif q==2:
            freq2count[initial] -=1
            if initial:
                num2freq[val] -= 1
            freq2count[num2freq.get(val,0) ] +=1
                
        elif q==3:
            ret.append(1 if freq2count.get(val) else 0)
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
