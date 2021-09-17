## Recursion: Fibonacci Numbers

```python 
def fibonacci(n):

    # Write your code here.
    # if n==0:
    #     return 0
    # if n==1:
    #     return 1
    
    # return fibonacci(n-1) + fibonacci(n-2)

    # option 2
    if n<2: return n
    #  0    1   1   2   3   5
    a,b,c = 0,1,1
    for i in range(2,n+1):
        c = a+b
        a = b
        b =c
    return c
```

## Recursion: Davis' Staircase

```python

def stepPerms(n):
    # Write your code here
    
    #   1   2   3   4   5   6   7   
    #   1   2   4   7   13  25  44
    
    if n==1:
        return 1
    if n==2:
        return 2
    if n==3:
        return 4
    a,b,c,ret = 1,2,4,0
    for i in range(4, n+1):
        ret = a+b+c
        a = b
        b =c
        c = ret
    return ret
```

## Recursive Digit Sum


```python
def dig(n):
    if n<10:
        return n
    m = 0
    while n:
        m += n%10
        n //= 10
    return dig(m)
def superDigit(n, k):
    # Write your code here
    m = 0
    for c in n:
        m += int(c)%10
        
    return dig(m*k)

```


## Crossword Puzzle

