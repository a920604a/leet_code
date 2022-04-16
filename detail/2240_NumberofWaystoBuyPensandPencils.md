---
title: 2240. Number of Ways to Buy Pens and Pencils
tags:
    - Math
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils/)
## solution 
```c++
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        //  cost1* x + cost2 * y <=total  所有解的個數
        
        // option 1  brute force
        
        // long long ret = 0;
        // int n = total/cost1, m = total/cost2;
        // for(int i=0;i<=n;++i){
        //     for(int j=0;j<=m;++j){
        //         if(i*cost1+j*cost2<=total) {
        //             ret++;
        //         }
        //     }
        // }
        // return ret;
        
        // option 2 pruning
        // long long ret = 0;
        // int n = total/cost1, m = total/cost2;
        // for(int i=0;i<=n;++i){
        //     int k =0;
        //     for(int j = m;j>-1;j--){
        //         if(cost1*i + cost2*j <=total){
        //             k = j;
        //             break;
        //         }
        //     }
        //     ret+= k+1;
        // }
        // return ret;
        
        long long ret = 0;
        if(total<cost1 && total <cost2){
            return 1;
        }
        else if(total<cost1){
            ret = (total/cost2) +1;
            return ret;
        }
        else if(total<cost2){
            ret = (total/cost1) +1;
            return ret;
        }
        int val1 = max(cost1, cost2), val2 = min(cost1, cost2);
        int n = total/val1;
        // n 短邊
        for(int i=0;i<=n;++i){
            ret+= (total/val2)+1;
            total-=val1;   
        }
        return ret;
    }
};
```

## analysis
- time complecity `O(n)`
- space complecity `O(1)`