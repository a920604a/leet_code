---
title: 187. Repeated DNA Sequences
tags:  
    - Bit Manipulation
    - hash table
    - sliding window
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/repeated-dna-sequences/)

## solution
#### option 1 - hash
```c++
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        int n = s.size();
        if(n<10) return ret;
        unordered_map<string, int> memo;
        for(int i=9;i<n;++i){
            string cur = s.substr(i-9, 10);
            if(memo[cur] ==1 ){
                ret.push_back(cur);
            }
            memo[cur]++;
        }
        return ret;
    }
};
```


#### option 2 - sliding window
```c++
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        // slide window
        string window;
        unordered_map<string, int> ret;
        int l=0, r=0;
        while(r<s.size()){
            
            char c = s[r++];
            // window[c]++;
            // window.append(c);
            window +=c;
            
            if(r-l>10){
                char d = s[l++];
                // window[d]--;
                window.erase(0,1);
                
            }
            
            // ret[s.substr(l,r-l)]++;
            ret[window]++;
        }
        
        vector<string> ans;
        for(auto it = ret.begin() ; it!=ret.end() ;++it){
            // cout<<it->first<<" "<<it->second<<endl;
            if(it->second > 1) ans.push_back(it->first);
        }
        
        
        return ans;
        
    }
};
```
#### option 3 - Bit Manipulation
```c++
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        if(s.size()<10) return ret;
        unordered_map<char, int> dict = {
            {'A',0},{'C',1},{'G',2},{'T',3}
        };
        // 20 = 10 * 2 bit(0,1,2,3)
        int mask = (1<<20)-1, n = s.size();
        int hash = 0;
        unordered_set<int> added, temp;
        for(int i=0;i<n;++i){
            hash = (hash<<2) + dict[s[i]];
            if(i>=9){
                hash &= mask;
                if(temp.count(hash) && !added.count(hash)){
                    ret.push_back(s.substr(i-9, 10));
                    added.insert(hash);
                }
                temp.insert(hash);
            }
        }
        return ret;
    }
};

```
## analysis
- time complexity `O(nlogn)`
- space complexity `O(n)`