class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {

        // option 1 STL O(m log m) time and O(m) time , m is the number of unique numbers
        map<int, int> m;
        int size = arr.size();
        priority_queue<pair<int, int>, vector<pair<int, int> >, less<pair<int, int> > > pq;

        for (int a : arr)
        {
            m[a]++;
        }
        for (auto mm : m)
        {
            pq.push(make_pair(mm.second, mm.first));
        }

        int count = 0, ret = 0;
        while (!pq.empty())
        {
            if (count >= size / 2)
                break;
            pair<int, int> p = pq.top();
            count += p.first;
            ret++;
            pq.pop();
        }

        return ret;
    }
};