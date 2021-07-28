class Solution
{
private:
    // unordered_set<int> black;
    // int range ;

    unordered_map<int, int> mapping;
    int sz;

public:
    Solution(int n, vector<int> &blacklist)
    {
        // option 1 time out
        // black = unordered_set<int>(blacklist.begin(), blacklist.end());
        // range = n;

        // option 2 大致上觀念就是把黑名單的數字映射到索引sz後，其他正常數字則沒事
        // (7, [2,3,5])
        // mapping  2->666  3->666   5->666

        sz = n - blacklist.size();
        // 先將黑名單加入map
        for (int b : blacklist)
        {
            //
            mapping[b] = 666;
        }
        int last = n - 1;
        // mapping  2->6     3->4    5->666
        for (int b : blacklist)
        {
            // 如果b已在區間 [sz, n)，可以忽略
            if (b >= sz)
                continue;

            // 跳過黑名單中的數字
            while (mapping.count(last))
            {
                last--;
            }
            mapping[b] = last;
            last--;
        }
        // 將黑名單的數字交換 區間 [sz,n) ，同時把   [0, sz) 中黑名單映射到正常數字
    }

    int pick()
    {
        // option 1 time out
        // while(true){
        //     int p = rand() % this->range;
        //     if(black.find(p) == black.end()) return p;
        // }

        int index = rand() % sz;
        // 如果索引命中黑名單，需要映射到其他位置
        if (mapping.count(index))
            return mapping[index];

        // 若沒命中黑名單直接返回
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */