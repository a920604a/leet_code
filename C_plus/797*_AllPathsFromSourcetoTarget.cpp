class Solution
{
public:
    void traverse(vector<vector<int> > &graph, int pos, vector<int> path, vector<vector<int> > &ret)
    {
        // DFS traverse
        int n = graph.size();
        // DFS
        // 添加節點s 到路徑
        path.push_back(pos);
        if (path.back() == n - 1)
        {
            // if(pos == n-1){ // 到達終點
            ret.push_back(path);
            path.pop_back();
            return;
        }

        // 遍歷每個相鄰節點
        for (int p : graph[pos])
        {
            traverse(graph, p, path, ret);
        }
        // 從路徑移出節點
        path.pop_back();
    }
    vector<vector<int> > allPathsSourceTarget(vector<vector<int> > &graph)
    {
        vector<vector<int> > ret;
        vector<int> path;
        traverse(graph, 0, path, ret);
        return ret;

        // BFS
        int n = graph.size()-1;
        vector<vector<int>> ret;
        queue<vector<int>> q;
        q.push({0});
        int len=1;
        while(!q.empty()){
            
            int size = q.size();
            for(int i=0;i<size ;++i){
                vector<int> path = q.front();
                q.pop();
                if(path.back() == n) {
                    ret.push_back(path);
                }
                
                for(int pos:graph[path.back()]){
                    vector<int> tmp = path;
                    tmp.push_back(pos);
                    q.push(tmp);
                }
            }
            len++;
        }
        return ret;
    }
};