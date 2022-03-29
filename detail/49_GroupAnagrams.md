---
title: 49. Group Anagrams

tags:  
    - hash table
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/group-anagrams/)

## solution

#### option 1 
用hash table 存下已出現的字串(排序過)及index

```c++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, int>mp;
        for(string str:strs){
            string cur = str;
            sort(cur.begin(), cur.end());
            if(mp.find(cur)!=mp.end()){
                int ind = mp[cur];
                ret[ind].push_back(str);
            }
            else{
                mp[cur] = ret.size();
                ret.push_back({str});
            }
        }
        return ret;
    }
};
```

##### option 2

用字元加上出現次數編碼後當作hash table的key，放進hash table
例如："eat" 編碼後 "a1e1t1"

```c++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ret;
        for(string str:strs){
            vector<int> vec(26,0);
            string t ;
            for(char c:str) vec[c-'a']++;
            for(int i=0;i<26;++i){
                if(vec[i]==0) continue;
                t +=string(1,i+'a') + to_string(vec[i]);
                // 按順序拜訪a-z，所以不同排列順序的字串會在hash table會有相同的key
            }
            mp[t].push_back(str);
        }
        for(auto a:mp) ret.push_back(a.second);
        return ret;
    }
};
```
## analysis
- option 1
    - time complexity `O(n*mlogm)` , m is the maximum of string
    - space complexity `O(n)`
- option 2
    - time complexity `O(n)`
    - space complexity `O(n)`