---
title: 2293. Min Max Game
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/min-max-game/)
## solution
```c++
class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        queue<int> q;
        for(int a:nums) q.push(a);
        while(q.size()!=1){
            int n = q.size();
            for(int i= 0 ;i<n/2;i++){
                if(i%2==0){
                    int a = q.front();
                    q.pop();
                    if(!q.empty()){
                        int b = q.front();
                        q.pop();
                        q.push(min(a, b));
                    }
                }
                else{
                    int a = q.front();
                    q.pop();
                    if(!q.empty()){
                        int b = q.front();
                        q.pop();
                        q.push(max(a, b));
                    }
                }
            
            }
        }
        return q.front();
        
    }
};
```
## analysis
- time complexity `O()`
- space complexity `O()`