---
title: 68. Text Justification
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/text-justification/)

## solution 
```c++
class Solution {
public:
    string process(vector<string>& cur, int len, int cur_len){
        string ret;
        int n = cur.size();
        if(n==1){
            ret+=cur[0];
            ret.append(len-cur_len,' ');
            return ret;
        }
        int blank_size = (len - cur_len)/(n-1);
        int mod = (len - cur_len)%(n-1);
        
        for(int i=0;i<cur.size();++i){
            if(i==cur.size()-1){
                ret+=cur[i];
            }
            else{
                ret+=cur[i];
                ret.append(blank_size,' ');
                if(mod>0) {
                    ret.append(1,' ');
                    mod--;
                }
                
            }
        }
        return ret;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        vector<string> cur;
        int cur_len = 0;
        for(int i=0;i<words.size();++i){
            string word = words[i];
            if(cur_len + cur.size()+word.size()<=maxWidth){
                cur.push_back(word);
                cur_len += word.size();
            }
            else{
                string temp =  process(cur, maxWidth, cur_len);
                ret.push_back(temp);
                cur_len = word.size();
                cur.clear();
                cur.push_back(word);
            }
        }
        
        if(!cur.empty()){
            string temp;
            for(int i=0;i<cur.size();++i){
                temp+=cur[i];
                if(i!=cur.size()-1) temp.append(1,' ');
            }
            if(temp.size() < maxWidth) temp.append(maxWidth-temp.size(),' ');
        
            ret.push_back(temp);
        }
        return ret;
    }
};
```

