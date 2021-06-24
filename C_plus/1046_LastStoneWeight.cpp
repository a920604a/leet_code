class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        // use STL priority_queue O(nlogn)
        int ret = 0;
        priority_queue<int> q;
        for (int i : stones)
            q.push(i);

        while (q.size() > 1)
        {
            int y = q.top();
            q.pop();
            int x = q.top();
            q.pop();
            int sum = y - x;
            q.push(sum);
        }
        return q.top();
    }
};