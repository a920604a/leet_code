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