---
title: 1408. String Matching in an Array
tags: 
    - hash table
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/string-matching-in-an-array/)


## solution

```python 
class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        ans = list()
        words = sorted(words, key = len)
        for i in range(len(words)):
            for j in range(i+1, len(words)):
                if words[i] in words[j]:
                    ans.append(words[i])
                    # 只加入一次
                    break
        return ans
```
```c++
class Solution {
public:
    bool isValid(string &a, string &b){
        int n = a.size(), m=b.size();
        for(int i=0;i<=m-n;++i){
            int count = 0;
            for(int j=0;j<n;++j){
                if(a[j]!=b[i+j]) break;
                else count++;
            }
            if( count ==n) return true;
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ret;
        int n = words.size();
        sort(words.begin(), words.end(), [](string &a, string &b){
            return a.size()<b.size();
        });
        for(int i=0;i<n;++i){
            for(int j = i+1;j<n;++j){
                if (isValid(words[i], words[j])){
                    ret.push_back(words[i]);
                    break;
                }
            }
        }
        return ret;
    }
};
```

## analysis
- time complexity `O(n^3)`
- space complexity `O(n)`