14

# Easy 
## Maximum Element


```python


def getMax(operations):
    # Write your code here
    stack = []
    maxsta = []
    ret = []
    for q in operations:
        temp = q.split()
        if len(temp)==2:
            val = int(temp[1])
            stack.append(val)
            if not maxsta or maxsta[-1] <= stack[-1]:
                maxsta.append(val)
        elif temp[0]=='2':
            val = stack[-1]
            stack.pop(-1)
            if val== maxsta[-1]:
                maxsta.pop(-1)
        else:
            ret.append(maxsta[-1])
                
    return ret
      
```
## Equal Stacks
All test is passed, i guess O(n) time complexity. Using index instead of pop(), because pop() spend O(n) time .
```python

def equalStacks(h1, h2, h3):
    # Write your code here
    
    s1, s2, s3 = map(sum, (h1,h2,h3))
    i,j,k = 0,0,0
    
    while h1 and h2 and h3:
        m = min(s1, s2, s3)
        while s1>m: 
            s1 -= h1[i]
            i+=1
        while s2>m:
            s2 -= h2[j]
            j+=1
        while s3>m: 
            s3 -= h3[k]
            k+=1
        if s1==s2==s3: return s1
            
    return 0

```


# Medium

## Balanced Brackets

```python
def isBalanced(s):
    # Write your code here
    sta = []
    for c in s:
        if c=='(' or c=='[' or c=='{':
            sta.append(c)
        else:
            if not sta:
                return "NO"
            elif sta[-1] == '(' and c==')':
                sta.pop(-1)
            elif sta[-1] == '[' and c==']':
                sta.pop(-1)
            elif sta[-1] == '{' and c=='}':
                sta.pop(-1)
            else:
                return "NO"
    return "YES" if len(sta)==0 else "NO"

```

## Waiter


```python
def waiter(number, q):
    # Write your code here
    n = max(number)    
    primes = []
    for i in range(2,n+1):
        p = True
        for j in range(2,int(math.sqrt(i))+1):
            if i%j==0:
                p = False
                break
            
        if p: primes.append(i)
            
    answer = []
    for p in primes[:q]:
        A,B = [],[]
        temp = number[::-1]
        for a in temp:
            if a% p ==0:
                B.append(a)
            else:
                A.append(a)
        answer.extend(B[::-1])
        number.clear()
        number.extend(A)        
    
    if A: answer = answer +A[::-1]
    return answer
```

# Failure
## Truck Tour



```python
def truckTour(petrolpumps):
    # Write your code here
    n= len(petrolpumps)
    start = 0
    tank = 0
    for (i,p) in enumerate(petrolpumps):
        gas, dis = p
        tank += (gas - dis)
        if tank<0:
            start = i+1;
            tank = 0
        
    return start if start!=n else n

```


## Queries with Fixed Length
```python
def solve(arr, queries):
    # Write your code here
    ret = []
    mx = max(arr)
    n = len(arr)
    for q in queries:
        # max interval
        # maintain monotonic queue        
        queue = []
        cand = []
        for i in range(n):
            while queue and arr[i]>queue[-1]:
                queue.pop(-1)
                
            queue.append(arr[i])            
            # cut left
            if i>=q and arr[i-q]==queue[0]:
                queue.pop(0)
            # save result
            if i>=q-1:
                cand.append(queue[0])
        ret.append(min(cand))  
    return ret
        

```


## Queue using Two Stacks

```python
# Enter your code here. Read input from STDIN. Print output to STDOUT

def func(queries:list):
    # time out 
    
    old, new = [],[]
    for q in queries:
        op = q[0]
        if op==1:
            new.append(q[1])
        elif op==2:
            if not old:
                while new:
                    old.append(new.pop(-1))
            old.pop(-1)
        else:
            print(old[-1] if old else new[0])
                    
                    
    # cheap
    # queue = []
    # for q in queries:
    #     op = q[0]
    #     if op==1:
    #         queue.append(q[1])
    #     elif op==2:
    #         queue.pop(0)                
    #     else:
    #         print(queue[0])
queries = []

for _ in range(int(input())):
    queries.append(list(map(int,input().split())))
    
    
# print(queries)
func(queries)

```


## Largest Rectangle


```python

def largestRectangle(h):
    # Write your code here
    stack = []
    h.append(0)
    ret = 0
    for i,a in enumerate(h):
        while stack and a <= h[stack[-1]]:
            t = stack.pop()
            if not stack:
                ret = max(ret, i*h[t] )
            else:
                ret = max(ret, (i-stack[-1]-1)*h[t])
        stack.append(i)
    return ret

```

## Simple Text Editor

```python
history = []
arr = ""
for i in range(int(input())):
    op = input().strip().split(' ')
    if op[0]=='4':
        # reverse old version
        arr = history.pop(-1)           
        
    elif op[0]=='3':
        idx = int(op[1])
        print(arr[idx-1])       
    elif op[0]=='2':
        history.append(arr)
        
        idx = int(op[1])
        arr = arr[0:len(arr)-idx]  
        
    elif op[0]=='1':
        history.append(arr)
        arr = arr+ op[1]

```


## Castle on the Grid

## Down to Zero II

## Game of Two Stacks

```python
# time out
def twoStacks(maxSum, a, b):
    # Write your code here
    i,j = 0,0
    n,m = len(a), len(b)
    count, removeVal = 0,0
    while i< n and j<m:
        if a[i]<= b[j]:
            if(removeVal + a[i] <= maxSum):
                count+=1
                removeVal += a[i]
                i+=1
            else:
                return count
        elif b[j]< a[i]:
            if removeVal +b[j] <= maxSum:
                removeVal += b[j]
                count+=1
                j+=1
            else:
                return count
    while i<n and  removeVal + a[i] <= maxSum:
        removeVal += a[i]
        count+=1
        i+=1
        
    while j<m and  removeVal + b[j] <= maxSum:
        removeVal += b[j]
        count+=1
        j+=1
        
    return count
                
  
```

## Poisonous Plants

monotonic stack

## AND xor OR
monotonic stack

