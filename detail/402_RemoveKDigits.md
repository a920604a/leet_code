# 402. Remove K Digits

###### tags: `leetcode` `monotonci stack`


## [problem](https://leetcode.com/problems/remove-k-digits/)

## solution
因為越前面位數越大，所以要先被移除，維護一個monotonic stack(從stack頂部遞減)

```c++
class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<char> sta;
        int n = num.size();
        for(int i=0;i<n;++i){
            while(k && !sta.empty() && num[i]-'0' < sta.top()-'0'){
                sta.pop();
                k--;
            }
            sta.push(num[i]);
        }
        while(k){
            k--;
            sta.pop();
        }
        string ret;
        while(!sta.empty()){
            ret = sta.top()+ret;
            sta.pop();
        }
        int i=0;
        int m = ret.size();
        while(i<m && ret[i]=='0') i++;
        string ans = ret.substr(i, m-i+1);
        return ans==""?"0":ans;
        
    }
};
```


## analysis
- time complexity `O(n)`
- space complexity `O(1)`
