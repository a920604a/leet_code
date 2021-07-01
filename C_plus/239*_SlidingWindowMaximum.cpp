class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {

        // option 1 brute timeout O(nk)
        //         vector<int> window(k,1);
        //         vector<int> maxWindow ;
        //         int n= nums.size();
        //         for(int i=0;i<=n-k;++i){
        //             // vector inner product
        //             int local_mx = INT_MIN;
        //             for(int j=i;j<i+k;++j){
        //                 local_mx = max(local_mx, nums[j]);
        //             }
        //             // cout<<local_mx<<endl;
        //             maxWindow.emplace_back(local_mx);

        //         }
        //         return maxWindow;

        // option 2 O(nlogn) STL multiset 紅黑樹 插入 刪除 O(logn)
        //         vector<int> maxWindow ;
        //         multiset<int> st;
        //         int n=nums.size();
        //         for (int i = 0; i < n; ++i){
        //             // 找到 nums[i-k] 位置 在針對此位置刪除，可避免 刪除到重複的元素
        //             if (i >= k) st.erase(st.find(nums[i - k]));
        //             st.insert(nums[i]);
        //             // cout<<*st.begin()<<" "<<*st.rbegin()<<endl;
        //             if (i >= k - 1) maxWindow.push_back(*st.rbegin());
        //             //multiset 是 升序排列的

        //         }

        //         return maxWindow;

        // option 3 priority queue = max-heap O(nlogn)
        //         priority_queue<pair<int,int>> q;
        //         vector<int> maxWindow ;
        //         int n=nums.size();
        //         for (int i = 0; i < n; ++i){
        //             while(!q.empty() && q.top().second <= i - k) q.pop();
        //             q.push({nums[i], i});
        //             if( i>=k-1)  maxWindow.emplace_back(q.top().first);

        //         }

        //         return maxWindow;

        // option 4 O(n) deque
        vector<int> maxWindow;
        int n = nums.size();
        deque<int> q;
        for (int i = 0; i < n; ++i)
        {
            if (!q.empty() && q.front() == i - k)
                q.pop_front();
            while (!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();

            q.push_back(i);
            if (i >= k - 1)
                maxWindow.push_back(nums[q.front()]);
        }

        return maxWindow;
    }
};