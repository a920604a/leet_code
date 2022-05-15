---
title: 2273. Find Resultant Array After Removing Anagrams
tags:
    - stack
categories: leetcode
comments: false
---


## [problems](https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/)
## solution
```c++
class Solution {
public:
    
    vector<string> removeAnagrams(vector<string>& words) {
        int n =words.size();
        stack<int> sta({0});
        vector<string> ret;
        for(int i=1;i<n;++i){
            string temp = words[i];
            sort(temp.begin(), temp.end());
            if(!sta.empty()){
                string a = words[sta.top()];
                sort(a.begin(), a.end());
                if(a==temp) continue;
                else{
                    sta.push(i);
                }
            }
        }
        while(!sta.empty()){
            int i = sta.top();
            ret.push_back(words[i]);
            sta.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
        
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(n)`