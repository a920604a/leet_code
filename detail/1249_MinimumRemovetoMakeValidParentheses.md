---
title: 1249. Minimum Remove to Make Valid Parentheses
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/)


## solution
1. 遍歷字串，遇到字母加進字串`ret`，遇到左括號push stack，遇到右括號且如果stack為空，則不加入字串`ret`，代表目前為止右括號出現次數多餘左括號，遇到右括號且stack 不為空則加入字串`ret`並pop stack。

2. 最後檢查是否有左括號在字串`ret`後方且沒有對應的右括號，並將他移除。


```c++
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> sta;
        string ret;
        for(char c:s){
            if(c>='a' && c<='z') ret+=c;
            else if(c=='(') {
                sta.push(c);
                ret+=c;
            }
            else{
                // )
                if(sta.empty()) continue;
                else{
                    sta.pop();
                    ret+=c;
                }        
            }
        }
        // "())()((("
        // 從後面移除多餘的左括號
        string ans;
        int n= ret.size();
        for(int i=n-1;i>-1;i--){
            if(ret[i]=='(' && !sta.empty()){
                sta.pop();
                continue;
            }
            else{
                ans+=ret[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(n)`