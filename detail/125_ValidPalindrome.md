# 125. Valid Palindrome



###### tags: `leetcode` `Two Pointers`

## [problem](https://leetcode.com/problems/valid-palindrome/)


## solution 

```c++
class Solution {
public:
    bool isValid(char &c){
        
        if(c >= '0' && c<='9') return true;
        if(c>='a' && c<='z') return true;
        if(c>='A' && c<='Z') return true;
        return false;
    }
    
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        int n= s.size()-1;
        int l=0, r =n;
        while(l<r){
            while(l<r && !isValid(s[l])) l++;
            while(l<r && !isValid(s[r])) r--;
            if(tolower(s[l])!=tolower(s[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`