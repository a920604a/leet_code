## Flipping bits


```cpp
long flippingBits(long n) {
    vector<int> v;
    int c = 32;
    while(c){
        v.push_back( (n&1)?0:1 );
        n>>=1;
        c--;
    }
    long ret = 0;
    for(int i=v.size()-1;i>-1 ;i--){
        ret <<=1;
        ret += v[i];
    }
    return ret;

}

// option 2 O(1) space

long flippingBits(long n) {
    long ret =0;
    int c = 32;
    while(c){
        ret <<=1;
        ret += ((n&1)?0:1);
        n>>=1;
        c--;
    }
    long ans = 0;
    c = 32;
    while(c){
        ans <<=1;
        ans += (ret&1);
        ret >>=1;
        c--;
    }
    return ans;

}

// option 3
long flippingBits(long n) { 
    return (n^(0xffffffff));
}

```
```python 
def flippingBits(n):
    # Write your code here
    temp , cnt = 0,32
    while cnt:
        cnt-=1
        temp <<=1
        temp += 1 if n&1==0 else 0
        n >>=1
    ans, cnt = 0, 32
    while cnt:
        cnt-=1
        ans <<=1
        ans += temp&1
        temp>>=1
    return ans
    # return n^(2**32-1)
```

## Time Complexity: Primality


```python
def primality(n):
    # Write your code here
    if(n==1): return "Not prime"
    for i in range(2, 1+int(math.sqrt( n ) )):
        if(n%i==0): return "Not prime"
    return "Prime"
```



