class UF
{
private:
    int count;
    vector<int> parent;
    vector<int> size;

public:
    UF(int n)
    {
        count = n;
        parent.reserve(n);
        size.reserve(n);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int x)
    {

        while (parent[x] != x)
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    void unionSet(int p, int q)
    {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)
            return;

        if (size[rootP] > size[rootQ])
        {                               // 看誰資源多
            parent[rootQ] = rootP;      // Q認P為首領
            size[rootP] += size[rootQ]; // P 將Q 資源加入到自己底下
        }
        else
        {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
    }
    bool connected(int p, int q)
    {
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }
};
class Solution
{
public:
    bool equationsPossible(vector<string> &equations)
    {
        // 很多使用DFS解決的問題，也可以用union find演算法 解決。
        // 26個字母，各成一派
        UF *uf = new UF(26);
        // 讓等式的字母做連通
        for (string eq : equations)
        {
            if (eq[1] == '=')
            {
                char x = eq[0];
                char y = eq[3];
                uf->unionSet(x - 'a', y - 'a');
            }
        }

        // 檢查不等式關係是否打破 相等關係的連通性
        for (string eq : equations)
        {
            if (eq[1] == '!')
            {
                char x = eq[0];
                char y = eq[3];
                if (uf->connected(x - 'a', y - 'a'))
                    return false;
            }
        }
        return true;
    }
};