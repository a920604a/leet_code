class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        // option 1 O(n) brute force  time out
        //         int n =nums.size();
        //         vector<int> vec(n,0);

        //         for(int i=0;i<n-1;++i){
        //             int tmp =0;
        //             for(int j=i+1;j<n;++j){
        //                 tmp +=(nums[j]<nums[i])?1:0;
        //             }
        //             vec[i] = tmp;
        //         }
        //         return vec;
        // option 2 O(nlogn) binary search 每個元素 逐個插入以排序的陣列，因為是已排序的陣列，所以插入時的索引及代表過往有多少數字小於該數字。注意從原始陣列尾部逐個插入。
        // O(nlogn) 還是time limit exceeded
        //         int n= nums.size();
        //         vector<int> vec;
        //         vector<int> ret(n,0);
        //         for(int i=n-1;i>-1;i--){
        //             int l = 0, r=vec.size();
        //             while(l<r){
        //                 int mid = l +(r-l)/2;
        //                 if(vec[mid]<nums[i]) l=mid+1;
        //                 else r = mid;
        //             }
        //             vec.emplace(vec.begin() + l, nums[i]);
        //             ret[i] = l;
        //         }

        //         return ret;
    }
};