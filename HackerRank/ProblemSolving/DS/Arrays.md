基礎題

## Arrays - DS

```python
def reverseArray(a):
    # Write your code here
    return a[::-1]

```

## 2D Array - DS

```python
def hourglassSum(arr):
    # Write your code here
    ret = -9*7
    for i in range(1,5):
        for j in range(1,5):
            ret = max(ret ,
                    arr[i-1][j-1] + arr[i-1][j] + arr[i-1][j+1] +
                                    arr[i][j] + 
                    arr[i+1][j-1] + arr[i+1][j] + arr[i+1][j+1]
                )
        
    return ret
```


## Dynamic Array

```python
def dynamicArray(n, queries):
    # Write your code here
    ret = []
    lastAnswer = 0
    arr = [[] for f in range(n)]
    for (q, x,y) in queries:
        idx  = (x ^ lastAnswer )%n
        if q==1:
            arr[idx].append(y)
        elif q==2:
            index = y%len(arr[idx])
            lastAnswer = arr[idx][index]
            ret.append(lastAnswer)    
    return ret
```


## Left Rotation


```python

def rotateLeft(d, arr):
    # Write your code here
    n = len(arr)
    ret = []
    for i in range(n):
        ret.append( arr[(d+i)%n])
    return ret    
```

## Sparse Arrays
```python
def matchingStrings(strings, queries):
    # Write your code here
    ret = []
    str2freq = dict()
    for s in strings:
        str2freq[s] = str2freq.get(s, 0) + 1
    print(str2freq)
    
    for q in queries:
        ret.append(str2freq.get(q,0))
    return ret

```



## Array Manipulation

```python

def arrayManipulation(n, queries):
    # Write your code here
    # prefix sum
    prefix = [0 for i in range(n)]
    for (s,e,val) in queries:
        prefix[s-1] +=val
        if e< n:
            prefix[e] -=val
    ret ,item= 0,0
    for i in range(n):
        item += prefix[i] # avoid time out
        ret = max(ret, item)
    return ret
```

## Array and simple queries


```python 
from array import array

n, n_queries = map(int, input().split())
data = array('L', map(int, input().split()))
assert len(data) == n
for m in range(n_queries):
    t, i, j = map(int, input().split())
    if t == 1:
        aux1 = i - 1
        aux2 = j - aux1
        data[:aux2], data[aux2:j] = data[aux1:j], data[:aux1]
    else:
        aux1 = i - 1
        aux2 = aux1 + n - j
        data[aux1:aux2], data[aux2:] = data[j:], data[aux1:j]
print(abs(data[0] - data[-1]))
print(*data)
```