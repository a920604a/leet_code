## QHEAP1

```python
from heapq import heappush, heappop
n = int(input())

heap = []
item_lookup = set()

for _ in range(n):
    args = list(map(int, input().split()))
    
    if args[0] == 3:
        while heap[0] not in item_lookup:
            heappop(heap)
        print(heap[0])
    elif args[0] ==1:
        heappush(heap, args[1])
        item_lookup.add(args[1])
        
    elif args[0] ==2:
        item_lookup.discard(args[1])
        

```
## Jesse and Cookies

```python

from heapq import heappush, heappop, heapify
def cookies(k, A):
    # Write your code here
    heapify(A)
    op = 0
    while len(A)>=2 and A[0]<k:
        a = heappop(A)
        b = heappop(A)
        sw = a*1 + b*2
        heappush(A,sw)
        op+=1
        
    if A[0]<k:
        return -1
    return op
```