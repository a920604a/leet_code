class Solution
{
public:
    void backtracking(vector<int> &arr, int start, vector<bool> &visited)
    {

        int n = arr.size();

        if (start < 0 || start > n - 1 || visited[start])
            return;
        visited[start] = true;

        if (arr[start] == 0)
            return;
        backtracking(arr, start + arr[start], visited);
        backtracking(arr, start - arr[start], visited);
    }
    bool canReach(vector<int> &arr, int start)
    {
        // DFS
        // int n = arr.size();
        // vector<bool> visited(n, false);
        // backtracking(arr, start, visited);
        // for(int i=0;i<n;++i){
        //     if(arr[i] == 0 && visited[i]) return true;
        // }
        // return false;

        // BFS  + queue
        queue<int> q;
        int n = arr.size();
        vector<bool> visited(n, false);

        q.push(start);
        visited[start] = true;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                int p = q.front();
                q.pop();
                if (arr[p] == 0)
                    return true;
                if (p + arr[p] < n && visited[p + arr[p]] == false)
                {
                    q.push(p + arr[p]);
                    visited[p + arr[p]] = true;
                }
                if (p - arr[p] > -1 && visited[p - arr[p]] == false)
                {
                    q.push(p - arr[p]);
                    visited[p - arr[p]] = true;
                }
            }
        }
        return false;
    }
};