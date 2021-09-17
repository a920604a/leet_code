## Hash Tables: Ice Cream Parlor
兩數總和
```python
def whatFlavors(cost, money):
    # Write your code here
    # don't sort and sum two number is target
    ht = dict()
    for i, c in enumerate(cost):
        if money-c in ht:
            print(ht[money-c]+1, i+1)
        ht[c] = i
    
    
```

## Pairs


```python 
def pairs(k, arr):
    # Write your code here
    arr.sort()
    ret = 0
    for i in range(len(arr)-1):
        # binary search
        target = k + arr[i]
        l = i+1
        r = len(arr)-1
        while(l<=r):
            mid = l + (r-l)//2
            if(arr[mid] == target):
                ret +=1
                break
            elif  arr[mid]<target:
                l = mid+1
            else:
                r = mid-1
                
    return ret
# option two pointers 
def pairs(k, arr):
    # Write your code here
    arr.sort()
    i,j = 0,1
    ret = 0
    while j<len(arr) :
        diff = arr[j] - arr[i]
        if (diff ==k):
            ret+=1
            j+=1
        elif diff<k:
            j+=1
        else:
            i+=1
    return ret
```

## Triple sum

```python
# Complete the triplets function below.
def triplets(a, b, c):
    a = list(sorted(set(a)))
    b = list(sorted(set(b)))
    c = list(sorted(set(c)))    
    i,j,k = 0,0,0
    ret = 0
    while j<len(b):
        while i<len(a) and a[i]<=b[j]:
            i+=1
        while k<len(c) and c[k]<= b[j]:
            k+=1
        ret += i*k
        j+=1
        
    return ret
```


## Maximum Subarray Sum

```python 

from bisect import bisect,insort
def maximumSum(a, m):
    # Write your code here
    ret = []
    max_sum = 0
    cur = 0;
    for i in range(len(a)):
        cur = (cur + a[i])%m       

        # select lowest number which higher than cur in array
        pos = bisect(ret, cur)
        d = 0 if pos == i else ret[pos]
        max_sum = max(max_sum, (cur + m - d) % m)
        # insert position 
        insort(ret, cur)
        
    return max_sum
```



## Minimum Time Required

```python

# Complete the minTime function below.
def getNumItems(machines, goal, days):
    # days 天可產生多少產品
    total = 0
    for m in machines:
        total += days//m
    return total
def minTime(machines, goal):
    
    machines.sort()
    l ,r= 0, machines[-1] *goal

    while (l<r):
        mid = l + (r-l)//2
        total = getNumItems(machines, goal, mid)
        
        if total >= goal:
            r = mid
        else:
            l = mid+1
    
    return int(l)        
    

```


```python

```


# Fail

## Swap Nodes [Algo]


## Making Candies
