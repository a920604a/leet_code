---
title: 2178. Maximum Split of Positive Even Integers
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/maximum-split-of-positive-even-integers)

## solution
- dfs -> time out
```c++
class Solution {
private:
    vector<long long> ret;
public:
    void traverse(vector<long long>& path,long long sum, vector<long long> & visited, long long l){
        
        if(sum<0) return;
        if(sum == 0){
            if(!ret.empty() && ret.size() < path.size()) ret = path;
            if(ret.empty()) ret = path;
            return;
        }
        
        for(long long i =l;i>-1;i-=2){
            
            if(visited[i] || i%2!=0) continue;
            visited[i] = true;
            path.push_back(i);
            traverse(path, sum-i, visited, i-2);
            visited[i] = false;            
            path.pop_back();
        }
    }
    vector<long long> maximumEvenSplit(long long finalSum) {
        // dfs
        vector<long long> visited(finalSum+1, false);
        vector<long long> path;
        traverse(path, finalSum, visited, finalSum);
        return ret;
    }
};
```
- math
```c++
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long>  ret;
        long long sum = 0;
        if(finalSum==1) return ret;
        if(finalSum%2!=0) return ret;
        long long i=2;
        while(sum+i<=finalSum){
            sum+=i;            
            ret.push_back(i);
            i+=2;
        }
        ret.back() += (finalSum-sum);
        return ret;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`