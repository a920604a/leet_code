


# 新手題
## Simple Array Sum

```python
def simpleArraySum(ar):
    return sum(ar)
```
## Solve Me First
```python
def solveMeFirst(a,b):
    return a+b
```
## Compare the Triplets

```python
def compareTriplets(a, b):
    ret = [0,0]
    for i,j in zip(a,b):
        if i>j:
            ret[0]+=1
        elif j>i:
            ret[1]+=1
    return ret
```
## A Very Big Sum
```python
def aVeryBigSum(ar):
    return sum(ar)
```
## Diagonal Difference

```python
def diagonalDifference(arr):
    # Write your code here
    n,m = len(arr), len(arr[0])
    diag1, diag2=0,0
    for i,j in zip(range(n), range(m)):
        diag1 += arr[i][j]
    for i,j in zip(range(n), range(m-1,-1,-1)):
        diag2 += arr[i][j]
    return abs(diag1-diag2)
        
    
```
## Plus Minus

```python
def plusMinus(arr):
    # Write your code here
    pos, neg ,n  = 0,0, len(arr)
    for i in arr:
        pos+= 1 if i>0 else 0
        neg +=1 if i<0 else 0
    print(pos/n)
    print(neg/n)
    print((n-pos-neg)/n)

```

## Staircase
```python
def staircase(n):
    for i in range(1,1+n):
        print(' '*(n-i)+'#'*i )
```
## Mini-Max Sum

```python
def miniMaxSum(arr):
    # Write your code here
    total = sum(arr)
    ret = [total,0]
    for a in arr:
        ret[0] = min(ret[0], total-a)
        ret[1] = max(ret[1], total-a)
    print(*ret)
```

## Birthday Cake Candles

```python
def birthdayCakeCandles(candles):
    return candles.count(max(candles))
    
```

## Time Conversion

```python
def timeConversion(s):
    # Write your code here
    AM_PM = s[-2:]
    s = s[:8]
    hh, mm, ss = [int(x) for x in s.split(":")]

    if AM_PM == 'PM' and hh != 12:
        return('{:02}:{:02}:{:02}'.format(hh+12, mm, ss))
    elif AM_PM == 'AM' and hh == 12:
        return('{:02}:{:02}:{:02}'.format(0, mm, ss))
    else:
        return('{:02}:{:02}:{:02}'.format(hh, mm, ss))

```


## Grading Students

```python
def gradingStudents(grades):
    new_grades =[]
    for g in grades:
        if g < 38:
            new_grades.append(g)
        else:
            if g%5 <3:
                new_grades.append(g)
            else:
                new_grades.append(g +  5- g%5)
            
    return new_grades
```



# 基礎題
## Apple and Orange

```python
def countApplesAndOranges(s, t, a, b, apples, oranges):
    # Write your code here
    ret_apple , ret_orange = 0,0    
    for ap in apples:
        if a+ap >= s and a +ap <=t:
            ret_apple+=1
    for op in oranges:
        if b+op >= s and b +op <=t:
            ret_orange+=1
    print(ret_apple)    
    print(ret_orange)    
    # print(sum([1 for x in apples if (x + a) >= s and (x + a) <= t]))
    # print(sum([1 for x in oranges if (x + b) >= s and (x + b) <= t]))
    
```

## Number Line Jumps

```python
def kangaroo(x1, v1, x2, v2):
    if v1>v2:
        if (x1 - x2) % (v2 - v1)==0:
            return "YES"
        else:
            return "NO"
    else:
        return "NO"
```

## *Between Two Sets


```python
from functools import reduce
def gcd(a, b):
    while b:
        a, b = b, a%b
    return a
def getTotalX(a, b):
    #     O(n log(n)) solution.
    # 1. find the LCM of all the integers of array A.
    # 2. find the GCD of all the integers of array B.
    
    lcm_a = reduce(lambda x,y: x*y//gcd(x,y), a)
    gcd_b = reduce(gcd, b)
    return (sum(1 for x in range(lcm_a,gcd_b+1,lcm_a) if gcd_b%x==0))

```
## Breaking the Records



```python
def breakingRecords(scores):
    # Write your code here
    minc , maxc = 0,0
    minval, maxval = scores[0], scores[0]
    for i,s in enumerate(scores):
        if s>maxval :
            maxval = s
            maxc +=1
        elif s<minval:
            minval = s
            minc +=1
    return [maxc, minc]
```

## Subarray Division

```python
def birthday(s, d, m):
    # Write your code here
    ret = 0
    n = len(s)
    for i in range(n-m+1):
        j = i
        total = 0
        while total < d and j<n:
            total+= s[j]
            j+=1
        if j-i==m and total == d:
            ret+=1
    return ret 
```
## Divisible Sum Pairs

```python
def divisibleSumPairs(n, k, ar):
    # Write your code here
    ret = 0
    for i in range(n-1):
        for j in range(i+1, n):
            if (ar[i] +ar[j])%k==0:
                ret+=1
    return ret
```

## Migratory Birds


```python
def migratoryBirds(arr):
    # Write your code here
    arr.sort()
    his = {}
    for a in arr:
        his[a] = his.get(a, 0) +1
    freq = 0
    val = 0
    for (k,v) in his.items():
        if v>freq:
            freq = v
            val = k
    return val
```
## Day of the Programmer



```python
def dayOfProgrammer(year):
    # Write your code here
    if year%4==0 and (year<1918 or year%400==0 or year%100!=0):
        return "12.09.%s" % year
    elif year == 1918:
        return "26.09.1918"
    return "13.09.%s" % year
```
## Bill Division

```python
def bonAppetit(bill, k, b):
    actual = sum(bill) - bill[k]
    actual /=2   
    if actual ==b:
        print("Bon Appetit")
    else:
        print(int(b- actual))
```
## Sales by Match

```python
def sockMerchant(n, ar):
    sock = {}
    count = 0
    for a in ar:
        sock[a] = sock.get(a,0) +1
    for (k,v) in sock.items():
        count += v//2
    return count
```

## Drawing Book

```python
def pageCount(n, p):
    return int(min(p//2,n//2-p//2))

```

## Counting Valleys

```python
def countingValleys(steps, path):
    height, vally = 0 , 0
    for p in path:
        if p =='U':
            height +=1
        else:
            height -=1
        if height==0 and  p == 'U':
            vally +=1
    return vally
```

## Electronics Shop


```python
def getMoneySpent(keyboards, drives, b):
    keyboards.sort()
    drives.sort()
    if keyboards[0] + drives[0] >b:
        return -1
    n ,m= len(keyboards), len(drives)
    returnval = 0
    for i in range(n):
        for j in range(m):
            if keyboards[i]+drives[j] <= b:
                returnval = max(returnval, keyboards[i]+drives[j])
    return returnval
```


# Not YET
## Cats and a Mouse



```python
```

