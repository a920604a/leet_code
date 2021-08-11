class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {

        // option 1 brute force O(n^2)
        //         int n = gas.size();
        //         vector<int> ret(n, 0);

        //         for(int i=0;i< n ;++i){
        //             int cur = gas[i];
        //             for(int j=i+1;j<=n+i;++j){
        //                 cur -=cost[(j-1)%n] ;

        //                 if(cur<0){
        //                     cur = -1;
        //                     break;
        //                 }
        //                 cur += gas[j%n];
        //             }
        //             ret[i] = cur;
        //         }

        //         int idx = -1, val = -1;
        //         for(int i = 0;i<n;++i){
        //             if(ret[i] > val){
        //                 idx = i;
        //                 val = ret[i];
        //             }
        //         }
        //         return idx;

        // option 2 O(n)
        // 剪枝
        //      1   2   3   4   5
        //      3   4   5   1   2
        //sum   -2  -4  -6  -3  0     將0作為起點在油箱變化量
        // 將sum 最低點作為起點，往上平移
        //      4   2   0   3   6
        // 最低點 index = 2+1 就是出發點
        // 找 sum 陣列中最小值的索引 +1
        // int n = gas.size(), sum = 0;
        // int minSum = INT_MAX;
        // int start = 0;
        // for(int i=0;i<n;++i){
        //     sum += (gas[i] - cost[i]);
        //     if(sum < minSum){
        //         minSum = sum;
        //         start = i+1;
        //     }
        // }
        // if(sum<0) return -1;
        // return start==n?0:start;

        // option 3 貪心有算法 O(n)

        // 如果選擇起點 i 作為起點，恰好無法 走到站點 j ，那麼i 和 j 中間的任一站點 k 都不可能作為起點。
        // 比如説從 站點1 出發，走到站點5時油箱油量為負數，那說明站點1 洽好無法 走到站點5，
        // 也就是說你無法從站點2 3 4 任一站點出發到達站點 5 因為站點5 到達時 油箱油量並然被減到負數。

        int n = gas.size();
        int sum = 0;
        for (int i = 0; i < n; ++i)
            sum += (gas[i] - cost[i]);
        if (sum < 0)
            return -1;
        int tank = 0;  // 油箱油量
        int start = 0; // 起點
        for (int i = 0; i < n; ++i)
        {
            tank += (gas[i] - cost[i]);
            if (tank < 0)
            {
                start = i + 1;
                tank = 0;
            }
        }
        return start == n ? 0 : start;
    }
};
