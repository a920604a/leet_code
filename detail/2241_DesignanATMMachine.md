---
title: 2241. Design an ATM Machine
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/design-an-atm-machine/)
## solution 
```c++
class ATM {
public:
    vector<long> bank;
    vector<int> mp = {20,50,100,200,500};
    ATM() {
        bank = vector<long>(5,0);
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0;i<5;++i) bank[i]+=(long)banknotesCount[i];
    }
    
    vector<int> withdraw(int amount) {
        int mock = amount ;
        vector<long> copy = bank;
        vector<int> used = vector<int>(5,0);
        for(int i=4;i>-1 ;i--){
            int times = mock/mp[i];
            times = min((long)times, copy[i]);
            // 剩餘 ATM 該種幣值的數量 與 貪婪地一次可取該幣別的最大數量
            // Amount of this currency remaining in the bank
            // 考慮到 ATM 剩餘數量不足以去做提款的動作
            mock -= times*mp[i];
            copy[i]-=times;
            used[i]+=times;
        }
        if(mock==0){
            bank = copy;
            return used;
        }
        else return {-1};
        
    }
};
```
## analysis
- time complexity `O(1)`
- space complexity `O(1)`