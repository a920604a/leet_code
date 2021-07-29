class Solution
{
private:
    vector<vector<int> > ret;

public:
    void traverse(vector<vector<int> > &graph, int s, vector<int> path)
    {

        // 添加節點s 到路徑
        path.push_back(s);

        int n = graph.size();
        if (s == n - 1)
        {
            // 到達終點
            ret.push_back(path);
            path.pop_back();
            return;
        }
        // 遍歷每個相鄰節點
        for (int v : graph[s])
        {
            traverse(graph, v, path);
        }
        // 從路徑移出節點
        path.pop_back();
    }
    vector<vector<int> > allPathsSourceTarget(vector<vector<int> > &graph)
    {

        vector<int> path;
        traverse(graph, 0, path);
        return ret;
    }
};


//option 2 save memory space and faster 

class Solution {
public:
    void traverse(vector<vector<int>> &graph, int s, vector<int> &path, vector<vector<int>> &ret ){
        
        int n = graph.size();
        path.push_back(s);
        
        if(s == n-1){
            // 到達終點
            ret.push_back(path);
            path.pop_back();
            return;
        }
        for(int n:graph[s]){
            
            traverse(graph, n, path, ret);
        }
        path.pop_back();        
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> ret;
        vector<int> path;
        traverse(graph, 0, path, ret);
        return ret;
    }
};


