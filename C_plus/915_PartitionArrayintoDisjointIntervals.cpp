class Solution
{
public:
    int partitionDisjoint(vector<int> &nums)
    {

        int n = nums.size();

        //  5   0   3   8   6
        //  5   5   5   8   8   lmax
        //  0   0   3   6   6   rmin

        //  1   1   1   0   6   12
        //  1   1   1   1   6   12  //lmax
        //  0   0   0   0   6   12  // rmin

        //         vector<int> lmax(n, nums[0]) , rmin(n, nums[n-1]);

        //         for(int i=1;i<n;++i) lmax[i] = max(lmax[i-1], nums[i] );
        //         for(int i=n-2;i>-1;i--) rmin[i] = min(rmin[i+1], nums[i] );

        //         // for(int l:lmax) cout<<l<<" ";
        //         // cout<<endl;
        //         // for(int r:rmin) cout<<r<<" ";
        //         int ret = 0;

        //         for(int i =0;i<n-1;++i){
        //             if(lmax[i]<=rmin[i+1]){
        //                 return i+1;
        //             }
        //         }
        // return 0;

        // option 2 optimize
        // lmax 透過第二個for迴圈一起做，以變數取代lmax陣列
        //         vector<int> rmin(n, nums[n-1]);
        //         for(int i=n-2;i>-1;i--) rmin[i] = min(rmin[i+1], nums[i] );;

        //         int lmax = INT_MIN;
        //         for(int i=0;i<n-1;++i){
        //             lmax = max(nums[i], lmax);
        //             if(lmax<= rmin[i+1]) return i+1;
        //         }
        //         return 0;

        // option 3 三個變數，無需額外空間
        //             i   i   i   i   i
        //  初始值      5   0   3   8   6
        // idx =       0   1   2   2   2
        // preMax =    5   5   5   5   5
        // curMax =    5   5   5   8   8
        // return idx+1;

        //              i   i   i   i   i   i
        //              1   1   1   0   6   12
        //idx =         0   0   0   3   3   3
        //preMax =      1   1   1   1   1   1
        //curMax =      1   1   1   1   6   12

        int idx = 0, preMax = nums[0], curMax = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            curMax = max(curMax, nums[i]);
            if (nums[i] < preMax)
            {
                preMax = curMax;
                idx = i;
            }
        }
        return idx + 1;
    }
};