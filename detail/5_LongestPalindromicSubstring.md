# 5. Longest Palindromic Substring


###### tags: `leetcode` `Two Pointers` `dp` `Blind Curated 75`

## [problem](https://leetcode.com/problems/longest-palindromic-substring/)

最長回文子字串
## solution
#### option 1 - two pointers
- 利用雙索引，從拜訪到的字元，當拜訪到字元，相鄰字元都一樣，則向左向右擴散
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
- option 1 - two pointers
    - time complexity `O(n^2)`
    - space complexity `O(1)`
