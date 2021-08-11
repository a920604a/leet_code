class Solution
{
public:
    vector<bool> visited;
    vector<bool> onPath;
    bool hasCycle = false;

    void traverse(vector<list<int> > &graph, int s, vector<int> &path)
    {

        if (visited[s])
            return;
        // cout<<s<<" ";

        // 遍歷到s
        visited[s] = true;

        for (int to : graph[s])
        {
            traverse(graph, to, path);
        }
        //必須post order 才能保證先修完子節點課程才能修此課程
        path.push_back(s);
    }
    vector<int> findOrder(int numCourses, vector<vector<int> > &prerequisites)
    {

        // graph 建造
        vector<list<int> > graph(numCourses);

        for (auto v : prerequisites)
        {
            int from = v[1];
            int to = v[0];
            graph[from].push_back(to);
        }

        // 先檢測 圖是否有環

        if (canFinish(numCourses, graph))
            return {};

        // traverse
        vector<int> path;
        visited = vector<bool>(numCourses, false);
        for (int i = 0; i < numCourses; ++i)
        {
            traverse(graph, i, path);
        }

        //  後序遍歷 + reverse 等於 拓樸排序
        reverse(path.begin(), path.end());
        return path;
    }
    bool canFinish(int numCourses, vector<list<int> > &graph)
    {
        // 檢查圖是否有環
        visited = vector<bool>(numCourses, false);
        onPath = vector<bool>(numCourses, false);
        for (int i = 0; i < numCourses; ++i)
        {
            // 因為可能不是所有節點都有相連
            traverse(graph, i);
        }
        return hasCycle;
    }

    void traverse(vector<list<int> > &graph, int s)
    {
        if (onPath[s])
        {
            hasCycle = true;
            return;
        }
        if (visited[s])
            return;
        // pre-order
        // 將節點 標記已遍歷
        visited[s] = true;
        // 開始遍歷節點
        onPath[s] = true;

        for (int to : graph[s])
        {
            traverse(graph, to);
        }
        onPath[s] = false;
    }
};