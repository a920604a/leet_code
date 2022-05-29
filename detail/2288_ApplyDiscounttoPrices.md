---
title: 2288. Apply Discount to Prices
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/apply-discount-to-prices/)

## solution
```c++
class Solution {
public:
    vector<string> split(string strs, char delimiter){
        vector<string> ret;
        string cur;
        for(char c:strs){
            if(c == delimiter){
                ret.push_back(cur);
                cur.clear();
            }
            else cur+=c;
        }
        ret.push_back(cur);
        return ret;
    }
    bool isValid(string str){
        if(str[0]!='$') return false;
        if(str.size() ==1) return false;
        for(int i=1;i<str.size() ; ++i){
            int c = str[i]-'0';
            if(c < 0 || c> 9) return false;
        }
        return true;
    }
    
    string discountPrices(string sentence, int discount) {
        // parser
        vector<string> parser = split(sentence, ' ');
        string ret;
        for(int i=0;i<parser.size() ; ++i){
            if(isValid(parser[i])){
                string temp = parser[i].substr(1);    
                // convert to int
                long long n = 0 ;
                for(char c:temp){
                    n = 10*n + c-'0';
                }
                n *= (100-discount);
                std::stringstream stream;
                stream<< std::fixed << std::setprecision(2) << (double)n/100.0;
                std::string t = stream.str();
                ret += "$" + t;
            }
            else ret+=parser[i];
            if(i!=parser.size()-1) ret+= ' ';
        }
        return ret;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(n)`