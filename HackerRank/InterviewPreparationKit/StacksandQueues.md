## Balanced Brackets



```python
def isBalanced(s):
    stack = []
    for c in s:
        if c=='(' or c=='[' or c=='{':
            stack.append(c)
        else:
            if not stack:
                return "NO"
            elif c==')' and stack[-1] =='(':
                stack.pop(-1)
            elif c==']' and stack[-1] =='[':
                stack.pop(-1)
            elif c=='}' and stack[-1] =='{':
                stack.pop(-1)
            else:
                return "NO"
    return "YES" if not stack else "NO"
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





# Fail
## Min Max Riddle


```python 
# time out sliding window
# monotonic queue
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


## Queues: A Tale of Two Stacks


```python
class MyQueue(object):
    def __init__(self):
        self.sta=[]
        self.sta2 = []
    
    def peek(self):
        if not self.sta2:
            while self.sta:
                self.sta2.append(self.sta.pop(-1))                
        return self.sta2[-1]
        
        
    def pop(self):
        if not self.sta2:
              while self.sta:
                self.sta2.append(self.sta.pop(-1))                
        return self.sta2.pop() 
            
        
    def put(self, value):
        self.sta.append(value)
        

```


## Poisonous Plants


```python
def poisonousPlants(plants):
    stack = []
    maxDays = 0
    for p in plants:
        days= 1

        while stack and stack[-1][0] >= p:
            _, d = stack.pop()
            days = max(days, d+1)
        if not stack:
            days = 0
        maxDays = max(maxDays, days)
        stack.append((p, days))
    return maxDays

```