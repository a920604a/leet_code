class Solution
{
private:
    struct MonotonicQueue
    {
    private:
        list<int> q;

    public:
        void push(int n)
        { // O(1)
            while (!q.empty() && q.back() < n)
            {
                q.pop_back();
            }
            q.push_back(n);
        }
        void pop(int n)
        { // O(1)
            if (n == q.front())
            {
                q.erase(q.begin());
            }
        }
        int max()
        { // O(1)
            return q.front();
        }
    };

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

        // option 1.1 sliding window time out
        int n = nums.size();
        vector<int> ret;
        if (n < k)
        {
            int _max = INT_MIN;
            for (int i = 0; i < n; ++i)
            {
                _max = max(_max, nums[i]);
                ret.push_back(_max);
            }
            return ret;
        }

        queue<int> window;
        for (int r = 0; r < n; r++)
        {
            window.push(nums[r]);
            if (r >= k - 1)
            {
                if (r != k - 1)
                    window.pop();
                // search queue local max
                int size = window.size(), local_max = INT_MIN;
                while (size)
                {
                    local_max = max(window.front(), local_max);
                    window.push(window.front());
                    window.pop();
                    size--;
                }
                ret.push_back(local_max);
            }
        }
        return ret;

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

        // option 5 monotonic queue
        int n = nums.size();
        MonotonicQueue window;
        vector<int> ret;

        for (int i = 0; i < n; ++i)
        {
            window.push(nums[i]);
            if (i >= k - 1)
            {

                ret.push_back(window.max());
                window.pop(nums[i - k + 1]);
            }
        }

        return ret;
    }
};