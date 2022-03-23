---
title: 371. Sum of Two Integers

tags:  
    - Bit Manipulation
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/sum-of-two-integers/)


## refer to 
- `&` 通常用於二進位的取位操作，例如一個數(x) `x & 1` 的結果就是取二進位的最末位，可以用來判斷奇偶。另外，相同位的兩個數字都為 1，則為 1，若有一個不為 1，則為0
- `^` 異或運算，如果某位不同則為1，否則為0。另外，還有`a^b = b^a`，`a^0=a`
- 加法可以用`&`、`^` 實現
```c++
a = 5
b = 17

int add(int a, int b){
    int sum = 0, count = 0;
    do{
        sum = a^b;
        count = (a&b)<<1;
        a = sum;
        b = count;
    }while(b!=0);
    return sum;
}
```
## solution



#### option 1 - iterative
- 加入` 0x7fffffff` 以防overflow 
```c++
class Solution {
public:
    int getSum(int a, int b) {
        while(a){
            int carry = (a&b&0x7fffffff)<<1, sum = a^b;
            a = carry, b = sum;
        }
        return b;
    }
};
```
#### option 2 - recursive
```c++
class Solution {
public:
    int getSum(int a, int b) {
        if(a==0) return b;
        int carry = (a&b&0x7fffffff)<<1, sum = a^b;
        return getSum(carry, sum);
    }
};
```

## analysis
- time complexity `O(1)`
- space complexity `O(1)`