class Solution
{
public:
    vector<int> countBits(int n)
    {
        // option 1 baseline O(nlogn)
        //         vector<int> ret;
        //         int tmp =0 ;
        //         for(int i =0;i<=n;++i){
        //             tmp = i;
        //             int count = 0;
        //             while(tmp){
        //                 count += (tmp&1);
        //                 tmp >>=1;
        //             }
        //             ret.push_back(count);

        //         }
        //         return ret;

        // option 2  inspiration from hint 2
        // O(n)
        //         if (n == 0) return {0};
        //         vector<int> ret = {0,1};
        //         int k =2,i=2;
        //         while(i<=n){
        //             for(i=pow(2,k-1); i<pow(2,k);++i){
        //                 if(i>n) break;
        //                 int t =  (pow(2,k)-pow(2,k-1))/2;
        //                 if(i<pow(2,k-1)+t) ret.push_back(ret[i-t]);
        //                 else ret.push_back(ret[i-t]+1);
        //             }
        //             k++;

        //         }
        //         return ret;

        // option 3 inspiration from  hint 3
        // divide odd/even O(n)
        //         vector<int> ret = {0};
        //         for(int i =1;i<=n;++i){
        //             if(i%2==0) ret.push_back(ret[i/2]);
        //             else ret.push_back(ret[i/2]+1);
        //         }

        //         return ret;

        // option 4
        // O(n)
        // 8 有幾個一 ==   ret[8&7]+1 == ret[1000&0111]+1 = ret[0]+1
        // 13 有幾個一 ==   ret[13&12]+1 == ret[1101&1100]+1 = ret[12] +1
        vector<int> ret(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            ret[i] = ret[i & (i - 1)] + 1;
        }
        return ret;
    }
};