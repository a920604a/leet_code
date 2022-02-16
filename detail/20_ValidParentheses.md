# 20. Valid Parentheses


###### tags: `leetcode` `stack` `Blind Curated 75`

## [problem](https://leetcode.com/problems/valid-parentheses/)


## solution 
```c++
class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for(char c:s){
            if(c=='(' || c=='[' || c=='{') sta.push(c);
            else{
                if(sta.empty()) return false;
                else if(c==')' && sta.top() == '(') sta.pop();
                else if(c==']' && sta.top() == '[') sta.pop();
                else if(c=='}' && sta.top() == '{') sta.pop();
                else return false;
            }
        }
        return sta.empty();
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(n)`
