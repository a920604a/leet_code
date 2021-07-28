
class Solution
{
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2)
    {
        // option 1
        int n = nums1.size();

        priority_queue<pair<int, int> > pq;
        for (int i = 0; i < nums2.size(); ++i)
        {
            pq.push(make_pair(nums2[i], i));
        }
        // (0,1) (1,10) (2,4) (3,11) => (3,11) (1,10) (2,4) (0,1)
        //  2   7   11  15           =>   15  11  7   2

        sort(nums1.begin(), nums1.end());

        int left = 0, right = n - 1;
        vector<int> ret(n, 0);

        while (!pq.empty())
        {
            auto pair = pq.top();
            pq.pop();
            int i = pair.second, maxVal = pair.first;
            if (maxVal < nums1[right])
            {
                ret[i] = nums1[right];
                right--;
            }
            else
            {
                // 比不過，拿最小值，送人頭
                ret[i] = nums1[left];
                left++;
            }
        }
        return ret;
    }
};