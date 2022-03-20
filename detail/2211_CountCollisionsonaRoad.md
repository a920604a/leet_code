---
title: 2211. Count Collisions on a Road
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/count-collisions-on-a-road/)

## solution

#### option 1 

```c++
class Solution {
public:
    int countCollisions(string directions) {
        int count = 0;
        int n = directions.size();
        // 撞到後會停在原地，後續有車子經過又會被撞
        // 將 RL SL 狀況下的L 改成 S狀態
        // 將 RL RS 狀態下的R 改成 S狀態
        for(int i=1;i<n;++i){
            char c = directions[i];
            if(c=='L'){
                if(directions[i-1] == 'R'){
                    // RL
                    count+=2;
                    directions[i] = 'S';
                    directions[i-1] = 'S';
                }
                else if(directions[i-1] =='S'){
                    // SL
                    count++;
                    directions[i] = 'S';
                }
            }
            else if(c=='S'){
                if(directions[i-1] == 'R'){
                    // RS
                    count++;
                    directions[i-1] = 'S';
                }
            }
        }
        
        // 在計算 有多少R 會撞到S
        int j=n-1;
        while(j>-1 && directions[j]=='R') j--;
        for(int i=0;i<=j;++i) count+=(directions[i] == 'R');
        
        return count;
    }
};
```




#### option 2 
```c++
class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size(), l = 0, r = n-1, count = 0;
        while(l<n && directions[l] == 'L') l++;
        while(r>-1 && directions[r] == 'R') r--;
        for(int i=l;i<=r;++i) count+=(directions[i]!='S')?1:0;
        return count;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`