# 121. Best Time to Buy and Sell Stock

###### tags: `leetcode` `dp`



## [problem](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

從股票價位陣列中找出，可以最大化淨利



## Solution

#### dp
- 維護一個dp 紀錄歷史至今最低價位，在用當天股價減去至今最低點，並更新ret

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //      7   1   5   3   6   4
        //mn    7   1   1   1   1   1
        int n = prices.size();
        vector<int> mn(n,INT_MAX);
        mn[0] = prices[0];
        for(int i=1;i<n;++i) mn[i] = min(mn[i-1], prices[i]);
        int ret = 0;
        for(int i =1;i<n;++i){
            ret = max(prices[i] - mn[i], ret);
        }
        return ret;   
    }
};
```
#### algo
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX, ret = INT_MIN;
        for(int p:prices){
            mn = min(mn, p);
            ret = max(ret, p-mn);
        }
        return ret;
    }
};
```
## analysis
- dp
    - time complexity `O(n)`
    - speed complexity `O(n)`
- algo
    - time complexity `O(n)`
    - space complexity `O(1)`