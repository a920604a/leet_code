class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        // priority queue O(nlogn)

        // priority_queue<int, vector<int>, greater<int>> pq;
        // for(int n:nums) pq.push(n);
        // return pq.top();

        // O(n)
        // int ret = INT_MAX;
        // for(int n:nums) ret = min(ret, n);
        // return ret;

        // binary search
        int n = nums.size(), l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid;
        }
        return nums[r];

        // option 2 
        int ret = nums[0];
        int n = nums.size(),  l = 0, r = n-1;
        while(l<=r){
            
            int mid = l + (r-l)/2;
            ret = min(nums[mid], ret);
            if(nums[r] >=nums[mid]) r = mid -1;
            else l = mid+1;
        }
        
        return ret;
    }
};