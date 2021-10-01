class UF
{
private:
    vector<int> parent, size;

public:
    UF(int n)
    {
        size = vector<int>(n);
        parent = vector<int>(n);
        for (int i = 0; i < n; ++i)
        {
            size[i] = 1;
            parent[i] = i;
        }
    }
    bool connect(int p, int q)
    {
        int pRoot = find(p);
        int qRoot = find(q);
        return pRoot == qRoot;
    }
    void unionSet(int p, int q)
    {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot)
            return;

        if (size[pRoot] > size[qRoot])
        {
            parent[qRoot] = pRoot;
            size[pRoot] += size[qRoot];
        }
        else
        {
            parent[pRoot] = qRoot;
            size[qRoot] += size[pRoot];
        }
    }
    int count()
    {
        // Count parent[x] = x
        int count = 0;
        for (int i = 0; i < parent.size(); ++i)
        {
            if (parent[i] == i)
                count++;
        }
        return count;
    }
    int find(int x)
    {
        while (x != parent[x])
        {
            x = parent[x];
        }
        return x;
    }
};
class Solution
{
public:
    int findCircleNum(vector<vector<int> > &isConnected)
    {

        int n = isConnected.size();
        UF uf = UF(n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (j == i)
                    continue;
                if (isConnected[i][j] == 1)
                    uf.unionSet(i, j);
            }
        }
        return uf.count();
    }
};