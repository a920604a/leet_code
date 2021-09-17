## Sorting: Bubble Sort

```python
def countSwaps(a):
    # Write your code here
    count = 0
    for i in range(len(a)-1):
        for j in range(len(a)-i-1):
            if(a[j]> a[j+1]):
                a[j] ,a[j+1] = a[j+1], a[j]
                count +=1
    
    print(f"Array is sorted in {count} swaps.\nFirst Element: {a[0]}\nLast Element: {a[-1]}")
```


## Sorting: Comparator

```python
class Player:
    def __init__(self, name, score):
        self.name = name
        self.score = score
    def __repr__(self):
        return f"name is {self.name}, score is {self.score}\n"            
    def comparator(a, b):
        if a.score > b.score:
            return -1
        elif a.score < b.score:
            return 1
        elif(a.score == b.score):
            if a.name> b.name:
                return 1
            else:
                return -1
        
```

## Mark and Toys

```python
def maximumToys(prices, k):
    # Write your code here
    prices.sort()
    count = 0
    for p in prices:
        if k>p:
            count+=1
            k -=p
        else:
            break
    return count
```

## Merge Sort: Counting Inversions

```python
def Merge(arr, l, mid, r):
    c= []
    ret = 0
    i = l
    j = mid+1

    while i<=mid and j<=r:
        if arr[i]> arr[j]:
            ret += (mid - i +1)
            c.append(arr[j])
            j +=1
        else:
            c.append(arr[i])
            i +=1
    
    while i<=mid:
        c.append(arr[i])
        i+=1
    while j<=r:
        c.append(arr[j])
        j+=1
    arr[l:r+1] = c
    return ret

def MergeSort(arr, l, r):
    ret = 0
    if(l<r):
        print(l,r)
        mid =  l + (r-l)//2
        ret += MergeSort(arr, l, mid)
        ret += MergeSort(arr, mid+1, r)
        ret += Merge(arr, l, mid, r)
    return ret

def countInversions(arr):
    # Write your code here
    
    return MergeSort(arr, 0, len(arr)-1)
    
```






# Fail
## Fraudulent Activity Notifications

```python 
def median(arr):
    arr.sort()
    n = int(len(arr)/2)
    if len(arr)%2==0:
        return (arr[n-1] + arr[n])/2
    else:
        return arr[n]
def activityNotifications(expenditure, d):
    # Write your code here

    ret = 0
    i = 0
    while(i+d<len(expenditure)):
        last = expenditure[i+d]
        med = median(expenditure[i:i+d])
        if(last >= med*2):
            ret+=1
        i+=1
    return ret
    

```