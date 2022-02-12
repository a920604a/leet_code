class Solution
{
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2)
    {
        priority_queue<pair<int, int> > pq;
        int n = nums1.size();
        vector<int> ret(n, 0);
        for (int i = 0; i < nums2.size(); ++i)
            pq.push(make_pair(nums2[i], i));
        sort(nums1.begin(), nums1.end());
        int l = 0, r = n - 1;
        while (!pq.empty())
        {
            pair<int, int> p = pq.top();
            pq.pop();
            int maxVal = p.first, i = p.second;
            if (maxVal >= nums1[r])
            {
                ret[i] = nums1[l++];
            }
            else
            {
                ret[i] = nums1[r--];
            }
        }
        return ret;
    }
};