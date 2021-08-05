class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // option 1
        // O(nlogn)
        // sort(nums.begin(), nums.end());
        // return nums[nums.size()-k];

        // option 2
        // priority queue  O(nlogn)
        // priority_queue<int> q(nums.begin(), nums.end());
        // int ret;
        // while(k){
        //     ret = q.top();
        //     q.pop();
        //     k--;
        // }
        // return ret;

         // option 3 quick sort + binary search 
        // O(N^2) worse case
        // 將partition 函數當作binary search的函數
        shuffle(nums); // 防止quick sort 的 worse case 加上洗牌 O(N)
        int lo = 0, hi = nums.size()-1;
        k = nums.size() - k;// 轉化成找最小
        while(lo <=hi){
            int p = partition(nums, lo, hi); // 確保 index-p 在陣列中是第 p 的數字
            if(p< k) lo = p+1;
            else if(p > k) hi = p-1;
            else return nums[p];
        }
        
        return -1;
    }
    // leetcode 384
    void shuffle(vector<int> & nums) {
        
        int n = nums.size();
        for(int i=0;i<n ;++i){
            int j =  i+ rand() % (n - i);  
            
            swap(nums[i], nums[j]);
        }
    }
    void swap(int &x, int &y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
    int Partition(vector<int> &nums, int l, int r)
    {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j < r; ++j)
        {
            if (nums[j] < pivot)
            {
                // swap
                i++;
                swap(nums[j], nums[i]);
            }
        }
        i++;
        swap(nums[i], nums[r]);
        return i;
    }
};