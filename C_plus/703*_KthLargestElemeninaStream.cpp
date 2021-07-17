/*
 * @Author: yuan
 * @Date: 2021-07-17 09:07:52
 * @LastEditTime: 2021-07-17 09:07:53
 * @FilePath: /leet_code/C_plus/703*_KthLargestElemeninaStream.cpp
 */
class KthLargest
{
private:
    priority_queue<int, vector<int>, greater<int> > q;
    int ans;

public:
    KthLargest(int k, vector<int> &nums)
    {
        ans = k;
        for (int num : nums)
        {
            q.push(num);
            if (q.size() > ans)
                q.pop();
        }
    }

    int add(int val)
    {
        q.push(val);
        if (q.size() > ans)
            q.pop();
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */