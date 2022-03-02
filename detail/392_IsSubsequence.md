---
title: 392. Is Subsequence
tags:  
    - Binary Search
    - Two Pointers
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/is-subsequence/)

## solution

#### option 1 - two pointers
```c++
class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int n = t.size(), m = s.size(), j=0;
        if(n<m) return false;
        for(int i=0;i<n;++i){
            if(t[i] == s[j]) j++;
        }
        return j==m;
    }
};
```

#### option 2 - dp

```c++
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        //      a   h   b   g   d   c   
        //  0   0   0   0   0   0   0
        //a 0   1   1   1   1   1   1
        //b 0   1   1   2   2   2   2
        //c 0   1   1   2   2   2   3
        
        for(int i=1;i<n+1;++i){
            for(int j=1;j<m+1;++j){
                if(s[i-1] == t[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m]==s.size();
    }
};
```

#### option 3 - *hash table + Binary Search

> follow up ，當很多個 `s` 不斷輸入時
 
假設 `t = "cacbhbc"`，需要一個hash table 存每個字元與方出現的位置，如`unordered_map<char, vector<int>>hash_table = {{"a", {1}}, {"b", {3,5}} , {"c", {0,2,6} }, {"h", {4}} }`，當 `s="abc"`，且已經匹配 `"ab"`了，那這時只需要用二元搜尋查找`hash_table["c"]` 這個 vector中比`4`大的索引。




```c++
class Solution {
public:
    int left_bound(vector<int> &nums, int target){
        int l = 0, r = nums.size();
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target) r = mid;
            else if(nums[mid] > target) r= mid;
            else l = mid+1;
        }
        return l;
    }
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> mp;
        int n = t.size();
        for(int i=0;i<n;++i){
            char c = t[i];
            if(mp.find(c)==mp.end()){
                mp[c].push_back(i);
            }
            else{
                mp[c].push_back(i);
            }
        }        
        int j =0; // index of t
        for(int i=0;i<s.size();++i){
            char c = s[i];
            // t 字串找不到 s[i] 這字元
            if(mp.find(c)==mp.end()) return false;
            int pos = left_bound(mp[c], j);
            // 二元搜尋區間中沒有字元 c
            if(pos == mp[c].size() )  return false;
            j = mp[c][pos]+1;
        }      
        return true;
    }
};

```



## analysis
- option 1 - two pointers
    - time complexity `O(n)`
    - space complexity `O(1)`
- option 2 - dp
    - time complexity `O(nm)`
    - space complexity `O(nm)`, n = len(s), m= len(t)
- option 3 - hash table + binary search
    - time complexity `O(nlogn)`
    - space complexity `O(1)`
