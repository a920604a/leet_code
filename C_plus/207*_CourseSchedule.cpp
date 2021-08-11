class Solution
{
public:
    vector<bool> visited;
    vector<bool> onPath;
    bool hasCycle = false;
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
    bool canFinish(int numCourses, vector<vector<int> > &prerequisites)
    {
        // Graph
        // topological Sort 有向無環圖

        // prerequisites = [[3,0],[3,1],[6,3],[7,3],[5,4],[9,5],[9,7]]
        vector<list<int> > graph(numCourses); // 相鄰串列

        for (auto edge : prerequisites)
        {
            int from = edge[1];
            int to = edge[0];
            graph[from].push_back(to);
        }

        // 檢查圖是否有環
        visited = vector<bool>(numCourses, false);
        onPath = vector<bool>(numCourses, false);
        for (int i = 0; i < numCourses; ++i)
        {
            // 因為可能不是所有節點都有相連
            traverse(graph, i);
        }
        for (bool b : visited)
            cout << b << " ";
        return !hasCycle;
    }
};