class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        // option 1 O(n)
        // use priority queue to cancel duplicate
        // priority_queue<int, vector<int>, greater<int>> pq;
        // for(int n:nums) pq.push(n);
        // return pq.top();

        // O(nlogn)
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r])
                l = mid + 1;
            // 讓子彈飛久一點
            else
                r--;
        }
        return nums[l];

        // option 2 
        int n = nums.size(), l = 0, r = n-1;
        int ret = nums.front();
        while(l<=r){
            int mid = l + (r-l)/2;
            ret = min(ret, nums[mid]);
            if(nums[mid] < nums[r]) r = mid-1;
            else if(nums[mid] > nums[r]) l = mid+1;
            else r--; // 讓子彈飛久一點
        }
        return ret;
    }
};