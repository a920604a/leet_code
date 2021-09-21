## Luck Balance


```python 

def luckBalance(k, contests):
    # Write your code here
    balance = 0
    grades =list()
    for (val, importance) in contests:
        if importance==0:
            balance += val
        else:
            grades.append(val)
    grades.sort(reverse = True)
    for i,g in enumerate(grades):
        if k>0:
            balance+= g
            k-=1
        else:
            balance-=g    
    return balance

```

## Minimum Absolute Difference in an Array


```python

def minimumAbsoluteDifference(arr):
    # Write your code here
    # for a in arr:
    #     if a<0:
    #         a *= -1
    arr.sort()
    ret = 10e+9+2
    for i in range(1, len(arr)):
        ret = min(ret, arr[i]-arr[i-1])
    return ret
```

## Greedy Florist

```python
def getMinimumCost(k, c):
    if k==len(c):
        return sum(c)
    
    c.sort(reverse=True)
    ret = 0
    w = 0
    i = 0
    while i<len(c):
        for j in range(i, i+k):
            if j<len(c):
                ret += c[j]*(w+1)
        w+=1
        i += k
    return ret
```

## Max Min

```python
def maxMin(k, arr):
    # Write your code here
    arr.sort()
    ret = 10e+5*k
    for i in range( len(arr)-k+1):
    #     print(i, i+k)
        temp = arr[i+k-1] - arr[i]
        ret = min(ret, temp)
    return ret
```