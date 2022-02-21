---
title: 1024. Video Stitching

tags:  
    - greedy
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/video-stitching/)

## solution
```c++
class Solution {
public:
    
    int videoStitching(vector<vector<int>>& clips, int time) {
        // 區間問題一律按照起點或終點排序。
        
        
        // step1. 先照起點升序，起點一致再用終點作降序
        // 因為clip 起點相同，那一定選最長的。這就是貪心的策略。
        // step2. 選定第一個clips[0]當作起點，比較所有起點小於clips[0][1]的區間。
        // 根據貪心策略，他們中終點最大的即是第二個clip小影片，再從第二個clip貪心選擇第三個以此類推。
        // step3. 重複step2 直到覆蓋區間[0,time]或是無法覆蓋則返回-1。
        sort(clips.begin(), clips.end(), [](vector<int> &a, vector<int>&b){
           
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        if(clips.size()==0 || time==0) return 0;
        // 紀錄選擇的clip個數
        int count = 0;
        int curEnd = 0, nextEnd = 0;
        int i =0, n = clips.size();
        while(i<n && clips[i][0]<= curEnd){ // 第一個區間必定是0當作起點
        
            // 選擇下一個clip
            while(i<n && clips[i][0] <= curEnd){
                nextEnd = max(nextEnd, clips[i][1]);
                i++;
            }            
            //找到下一個clip，更新curEnd
            count++;
            curEnd = nextEnd;
            // 表示已經可以拼接出 [0,time]
            if(curEnd>=time) return count;
        }        
        return -1;
    }
};
```
## analysis
- time complexity `O(nlogn)`
- space complexity `O(1)`