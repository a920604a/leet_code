class Solution
{
public:
    int minimumOperations(vector<int> &nums, int start, int goal)
    {
        // BFS => time limit
        vector<bool> visited(1001, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        int step = 0;
        while (!q.empty())
        {
            step++;
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                int p = q.front();
                q.pop();
                for (int n : nums)
                {
                    int temp = p + n;
                    if (temp == goal)
                        return step;
                    if (temp >= 0 && temp <= 1000 && !visited[temp])
                    {
                        q.push(temp);
                        visited[temp] = true;
                    }
                    temp = p - n;
                    if (temp == goal)
                        return step;
                    if (temp >= 0 && temp <= 1000 && !visited[temp])
                    {
                        q.push(temp);
                        visited[temp] = true;
                    }
                    temp = p ^ n;
                    if (temp == goal)
                        return step;
                    if (temp >= 0 && temp <= 1000 && !visited[temp])
                    {
                        q.push(temp);
                        visited[temp] = true;
                    }
                }
            }
        }
        return -1;
    }
};