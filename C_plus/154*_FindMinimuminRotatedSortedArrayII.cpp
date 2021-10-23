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
    }
};