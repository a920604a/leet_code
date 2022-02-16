# 5. Longest Palindromic Substring


###### tags: `leetcode` `Two Pointers` `dp`

## [problem](https://leetcode.com/problems/longest-palindromic-substring/)

## solution

#### option 1 - two pointers
- 利用雙索引從拜訪到的字元向所向右擴散
```c++
class Solution {
public:
    string longestPalindrome(string s) {
        int l =0,r = 0, n =s.size(),  start = 0, len = 0;
        for(int i=0;i<n;){
            l=r=i;
            while(r+1<n && s[r] == s[r+1]) r++;
            i = r+1;
            
            while(l>0 && r<n-1 && s[l-1] == s[r+1]){
                l--;
                r++;
            }
            if(r-l+1>len){
                len = r-l+1;
                start = l;
            }
        }
        return s.substr(start, len);
    }
};
```
#### option 2 - *dp

## analysis
- option 1 
    - time complexity `O(n)`
    - space complexity `O(1)`
