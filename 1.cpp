// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<vector>
int solution(string &A, string &B) {
    // write your code in C++14 (g++ 6.2.0)
    // 計算 有多少回合，每回合 15 分鐘 ，分別是 
    // HH:00 HH:15 HH:30 HH:45
    int count = 0;
    int ehour = 10*(A[0] - '0') + (A[1]-'0');
    int lhour = 10*(B[0] - '0') + (B[1]-'0');
    int hours = (lhour - ehour+24)  %24;
    int emin = 10*(A[3] - '0') + (A[4]-'0');
    int lmin = 10*(B[3] - '0') + (B[4]-'0');
    int mins = lmin - emin;
    if(hours==0 && mins ==0) return 0;

    // avoid 00:01 -> 01:01
    if(mins==0 &&  emin!=0 && emin!= 15 && emin!= 30 && emin!= 45){
        return hours*4-1;
    }
    // 未滿一小時
    if(hours == 0){
        if(mins< 0) return 0;
        // 不是整點開始
        if( emin!=0 && emin!= 15 && emin!= 30 && emin!= 45){
            // 前進到最近的整點
            int e = emin + 15 - (emin%15);
            int period = (lmin - e ) /15;
            return period;
        }
        else{
            // 整點開始
            int period = (lmin - emin ) /15;
            return period;

        }
    }
    else{
        count = hours *4;
        // 處理分鐘
        if(mins< 0) return count;
        // 不是整點開始
        if( emin!=0 && emin!= 15 && emin!= 30 && emin!= 45){
            // 前進到最近的整點
            int e = emin + 15 - (emin%15);
            int period = count;
            cout<< abs(lmin - e  ) /15<<endl;
            period += abs(lmin - e ) /15;
            return period;
        }
        else{
            // 整點開始
            int period = count;
            period += (lmin - emin ) /15;
            return period;
        }


    }

    return 0;

}
