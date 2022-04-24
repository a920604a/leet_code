---
title: 1396 Design Underground System
tags:
    - hash 
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/design-underground-system/)

## solution
```c++

class UndergroundSystem {
private:
    // 起點 終點 有哪些客人
    map<pair<string,string>,vector<int>> record;
    // 每位客人 在哪上車、上車時間
    map<int,pair<int,string>>clients;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        
        clients[id] = {t, stationName};
        
    }
    
    void checkOut(int id, string stationName, int t) {
        auto p = clients[id];
        // 完成一次搭乘，紀錄
        record[{p.second,stationName}].push_back(t - p.first);
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        double avg = 0.0;
        int len =0;
        for(auto v:record[{startStation,endStation }]){
            avg+=v;
            len++;
        }
        avg = avg/len;
        return avg;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
```