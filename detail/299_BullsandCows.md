---
title: 299. Bulls and Cows
tags:  
    - hash table
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/bulls-and-cows/)
## solution
#### option 1
```c++
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<int, vector<int>> mp, mpb;
        int a = 0, b=0;
        for(int i=0;i<secret.size() ; ++i) mp[secret[i]].push_back(i);
        for(int i=0;i<guess.size() ; ++i) mpb[guess[i]].push_back(i);
        for(auto m:mp){
            if(mpb.count(m.first)){
                vector<int> s = m.second, g = mpb[m.first];
                int l = 0,r = 0 ,  ca=0, cb= 0 ;
                while(l<s.size() && r<g.size()){
                    if(s[l] == g[r]){
                        ca++;
                        l++;
                        r++;
                    }
                    else if(s[l]<g[r]) l++;
                    else r++;
                }
                a+=ca;
                cb = min(s.size(), g.size()) - ca;
                b+=cb;
            }
        }
        return to_string(a)+"A"+to_string(b)+"B";
        
    }
};
```

#### option 2
```c++
class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> s(10,0), g(10,0);
        int a= 0, b = 0;
        for(int i=0;i<secret.size() ; ++i){
            char c1 = secret[i], c2 = guess[i];
            if(c1==c2) a++;
            else{
                s[c1-'0']++;
                g[c2-'0']++;
            }
          
        }
        for(int i=0;i<10;++i) b+=min(s[i], g[i]);
        return to_string(a)+"A"+to_string(b)+"B";
    }
};
```
## analysis
- time complexity `O(n+m)`
- space complexity `O(n+m)`