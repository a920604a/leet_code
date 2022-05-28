---
title: 2284. Sender With Largest Word Count
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/sender-with-largest-word-count/)

## solution
```c++
class Solution {
public:
    int split(string strs, char delimiters){
        int size = 0;
        for(char c:strs){
            if(c==delimiters) size++;
        }
        return ++size;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string, int> mp; //  If there is more than one sender with the largest word count, return the one with the lexicographically largest name.
        int n = senders.size();
        for(int i=0;i<n;++i){
            mp[senders[i]]+=split(messages[i], ' ');
        }
        string ret;
        int count =0;
        for(auto &[k,v]:mp){
            if(v>=count) {
                ret = k;
                count = v;
            }
        }
        return ret;
    }
};
```
```c++
class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> mp; //  If there is more than one sender with the largest word count, return the one with the lexicographically largest name.
        int n = senders.size();
        string ret;
        int count =0;
        for(int i=0;i<n;++i){
            int words = std::count(begin(messages[i]), end(messages[i]), ' ') + 1;
            int freq = mp[senders[i]] += words;
            if(freq > count || ( freq == count && senders[i]>ret ) ) {
                ret = senders[i];
                count = freq;
            }
        }
        return ret;
    }
};
```
