```python
def escape(s):
    l = 0
    r = 0
    ret = 0
    # next #
    while r <len(s):        
        while(l<len(s) and s[l] !='#'):
            l+=1
        r = l+1
        while(r<len(s) and s[r]!='#'):
            r+=1
        if r-l<3:
            l = r+1
        elif r>= len(s):
            break
        else:
            # check
            pre = s[l]
            for c in s[l+1:r]:
                if(pre=='!' and ord(c)>=97 and ord(c) <=122):
                    ret+=1
                pre =c 
                
            l = r+1
            
    return ret
            
    


print(escape("#ab!c#de!f"))
# 1
print(escape("##!r#po#"))
# 0
print(escape("#a!b#c"))
# 1
print(escape("#ab!c#de!f"))
# 1
print(escape("a!de#dwx!re!e##!##sdc!a!f"))
# 2
```


```python

def escape(s):
    # l = 0
    # r = 0
    # ret = 0
    # # next #
    # while r <len(s):        
    #     while(l<len(s) and s[l] !='#'):
    #         l+=1
    #     r = l+1
    #     while(r<len(s) and s[r]!='#'):
    #         r+=1
    #     if r-l<3:
    #         l = r+1
    #     elif r>= len(s):
    #         break
    #     else:
    #         # check
    #         pre = s[l]
    #         for c in s[l+1:r]:
    #             if(pre=='!' and ord(c)>=97 and ord(c) <=122):
    #                 ret+=1
    #             pre =c 
                
    #         l = r+1
    
    ret = 0 
    nows = -1
    th = 0
    for i in range(len(s)):
        if s[i] =='#':
            nows = nows*(-1)
            if nows == -1:
                ret += th
                th = 0
        else:
            if nows == 1:
                if s[i-1] == '!' \
                and ord(s[i]) >= ord("a") and \
                ord(s[i])<=ord("z"):
                    th+=1
                    
                
            
    return ret
            
    


print(escape("#ab!c#de!f"))
# 1
print(escape("##!r#po#"))
# 0
print(escape("#a!b#c"))
# 1
print(escape("#ab!c#de!f"))
# 1
print(escape("a!de#dwx!re!e##!##sdc!a!f"))
# 2
```