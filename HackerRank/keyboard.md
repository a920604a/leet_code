
```python
def entryTime(s, keypad):
    
    # make dict
    telephone = {}
    telephone[0] = [1,3,4]
    telephone[1] = [0,2,3,4,5]
    telephone[2] = [1,4,5]
    telephone[3] = [0,1,4,7,6]
    telephone[4] = [0,1,2,3,5,6,7,8]
    telephone[5] = [1,2,4,7,8]
    telephone[6] = [3,4,7]
    telephone[7] = [3,4,5,6,8]
    telephone[8] = [4,5,7]
    
    print(telephone[0])
    mp = dict()
    for i in  range(1,10):
        mp[i] = []
    for (i,k) in enumerate(keypad):
        for v in telephone[i]:
            mp[int(k)].append(int(keypad[v]))
    print(mp)
    ret = 0
    pre = int(s[0])
    
    for c in s[1:]:
        if pre ==int(c):
            pass
        elif int(c) in mp[pre]:
            ret +=1
            pre = int(c)
        else:
            ret +=2
            pre = int(c)
    return ret



print(entryTime("423692","923857614"))
# 8
print(entryTime("5111","752961348"))
# # 1
print(entryTime("91566165","639485712"))
# 11


```