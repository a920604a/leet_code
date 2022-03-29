---
title: PrefixSum
tags:  
    - Prefix Sum
categories: 
    - CS
    - Data Structure
    
comments: false
---


## 觀念

Prefix Sum 用於快速、频繁地計算一個索引區間内的元素之和。
```
array =         [-2    0   3   -5  2   -1]
prefix sum = [0  -2   -2   1   -4  -2  -3]
preSum[i] = preSum[i-1] + nums[i-1];   

array = [a, b,  c,  d,    e, f]
pre = [0,a, a+b, a+b+c, a+b+c+d, a+b+c+d+e, a+b+c+d+e+f]


```

Prefix diff
```
array =      [8  2   6   3   1]
diff =   [8  -6  4   -3  -2]
diff[i] = nums[i] + nums[i-1];    
// array[i..j] 的元素全部加 3，只需要diff[i]+=3
array = [a, b,  c,  d,    e]
diff = [a, (b-a), (c-b), (d-c), (e-d)]


// array[1..3] 的元素全部加 3，只需要diff[i]+=3, diff[3+1]-=3
array = [a, b+3, c+3, d+3, e]
diff = [a, (b-a+3), (c-b), (d-c), (e-d-3)]]

array[2...4] 的元素全部加 5
array = [a, b, c+5, d+5, e+5]
diff = [a, (b-a), (c-b+5), (d-c), (e-d)]

```




## 題目

Prefix Sum
- 303 Range Sum Query - Immutable (Easy)
- 304 Range Sum Query 2D - Immutable (Medium)
- 560. Subarray Sum Equals K (Medium)



Different Sum
- 1094 Car Pooling (Medium)
- 1109 Corporate Flight Bookings (Medium)