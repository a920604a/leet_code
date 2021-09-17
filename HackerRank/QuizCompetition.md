
```python

def teamSize(arr, count):
    
    ret = []
    
    for i in range(len(arr)-count+1):
        
        # max talent of min length array
        val = -1
        l = 0
        for j in range(i+count-1, len(arr)):
            s = set(arr[i:j+1])
            if len(s)> l :
                l = len(s)
                val = j-i+1
        ret.append(val)
    
    
    while( len(ret)<len(arr)):
        ret.append(-1)
        
    return ret
    
print(teamSize([1,2,3,2,1], 3))
# [3,4,3,-1,-1]
print(teamSize([1,1,2,2,3,1,3,2], 3))
# [5,4,4,3,4,3,-1,-1]
print(teamSize([7,5,3,4,6,1,7,2,4], 7))
# [8,7,-1,-1,-1,-1,-1,-1,-1]
```