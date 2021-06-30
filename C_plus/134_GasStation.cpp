class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        // option 1 O(n^2)
        //         int sum_g = accumulate(gas.begin(), gas.end(), 0);
        //         int sum_c = accumulate(cost.begin(), cost.end(), 0);
        //         if(sum_g-sum_c<0) return -1;
        //         int n =gas.size();

        //         for(int i=0;i<n;++i){
        //             int sum = 0;
        //             int j=0;
        //             while(j<n){
        //                 int idx = (i+j)%n;
        //                 sum +=gas[idx];
        //                 if(sum<0) break;
        //                 sum -= cost[idx];
        //                 if(sum<0) break;
        //                 j++;
        //             }
        //             if(sum>=0) return i;
        //         }
        //         return -1;

        // option 2 O(n)
        int remaind = 0, total = 0, start = 0;
        int n = gas.size();
        for (int i = 0; i < n; ++i)
        {
            total += gas[i] - cost[i];
            remaind += gas[i] - cost[i];
            if (remaind < 0)
            {
                remaind = 0;
                start = i + 1;
            }
        }
        return total < 0 ? -1 : start;
    }
};