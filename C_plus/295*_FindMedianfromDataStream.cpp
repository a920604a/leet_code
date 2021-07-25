class MedianFinder
{
private:
    //
    priority_queue<int> up; // 不變，因為C++ 預設小的優先取出
    priority_queue<int, vector<int>, greater<int> > down;

public:
    /** initialize your data structure here. */
    MedianFinder()
    {
        // 中位數位於金字塔的中間，將金字塔從中橫切一刀。可分為上下兩部分
        // 大於中位數的金字塔上部分用min heap up儲存
        // 小於中位數的金字塔下部分用max heap down 儲存
    }

    void addNum(int num)
    { // O(nlogn) time

        if (up.size() >= down.size())
        {
            up.push(num);
            down.push(up.top());
            up.pop();
        }
        else
        {
            down.push(num);
            up.push(down.top());
            down.pop();
        }
    }

    double findMedian()
    { // O(1) time

        // option 1
        if (up.size() > down.size())
            return up.top();
        else if (up.size() < down.size())
            return down.top();
        return (up.top() + down.top()) / 2.0;

        //option 2 相反數
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */