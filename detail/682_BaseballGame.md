---
title: 682. Baseball Game
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/baseball-game/)
## solution

```c++
class Solution {
public:
    int Convert(string str){
        int pos = 1;
        int i =0;
        if(str[i] == '-') {
            pos = -1;
            i++;
        }
        int num = 0;
        for(i;i<str.size();++i) num = 10*num+str[i] -'0';
        return pos*num;
    }
    int calPoints(vector<string>& ops) {
        vector<int> cur;
        for(string str:ops){
            if(str == "C"){
                cur.pop_back();
            }
            else if(str=="D"){
                cur.push_back(cur.back()*2);
            }
            else if(str=="+"){
                int size = cur.size();
                cur.push_back(cur[size-1]+cur[size-2]);
            }
            else{
                //conver to int
                int num = Convert(str);
                cur.push_back(num);
            }
        }
        int total = 0;
        for(int a:cur) total+=a;
        return total;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)`