## Balanced Brackets



```python
def isBalanced(s):
    # Write your code here
    ret = []
    for c in s:
        if c=='(' or c=='{' or c=='[':
            ret.append(c)
        else:
            if not ret:
                return "NO"
            elif ret[-1] == '[' and c==']':
                ret.pop()
            elif ret[-1] == '{' and c=='}':
                ret.pop()
            elif ret[-1] == '(' and c==')':
                ret.pop()
            else:
                return "NO"
    if ret :
        return "NO"
    return "YES"
```

## Largest Rectangle

```python
def largestRectangle(h):
    # Write your code here
    sta= [] 
    ret = 0
    h.append(0)
    for i,c in  enumerate(h):
        
        while sta and h[sta[-1]] >= c:
            t = sta.pop()
            if sta:
                ret = max(ret, (i- sta[-1]-1)*h[t] )
            else:
                ret = max(ret, i*h[t])           
        sta.append(i)
    return ret 

```




## 
# Fail
## Min Max Riddle

```python 
# time out sliding window
def minWindow(arr, w):
    n = len(arr)
    if w==1:
        return max(arr)
    elif w==n:
        return min(arr)
    else:
        ret = min(arr[:w])
        for i in range(1, n-w+1):
            window = min(arr[i:i+w])
            ret = max(window, ret)
        return ret
def riddle(arr):
    # complete this function
    ret = []
    for w in range(1, len(arr)+1):
        temp = minWindow(arr, w)
        ret.append(temp)
    return ret
```