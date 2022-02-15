# 242. Valid Anagram


###### tags: `leetcode` `hash table`

## [problem](https://leetcode.com/problems/valid-anagram/)


## solution 

#### option 1 - sorting
```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
    }
};
```
#### option 2 - hash table
```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> vec(26,0);
        for(char c:s) vec[c-'a']++;
        for(char c:t) vec[c-'a']--;
        return vec==vector<int>(26,0);
    }
};
```

## analysis
- option 1
    - time complexity `O(nlogn)`
    - space complexity `O(1)`
- option 2
    - time complexity `O(n)`
    - space complexity `O(1)`