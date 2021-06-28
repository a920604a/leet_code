// option 1 O(n)
// class FrontMiddleBackQueue {
// private:
//     vector<int> nums;
// public:
//     FrontMiddleBackQueue() {
//     }

//     void pushFront(int val) {
//         nums.emplace(nums.begin(), val);
//     }

//     void pushMiddle(int val) {
//         int mid = nums.size()/2;
//         nums.emplace(nums.begin()+mid, val);
//         cout<<endl;
//     }

//     void pushBack(int val) {
//         nums.emplace_back(val);
//     }

//     int popFront() {
//         if(nums.empty()) return -1;
//         int ret = nums[0];
//         nums.erase(nums.begin());
//         return ret;
//     }

//     int popMiddle() {
//         if(nums.empty()) return -1;
//         int mid = (nums.size()-1)/2, ret=0;
//         ret = nums[mid];
//         nums.erase(nums.begin()+mid);
//         return ret;
//     }

//     int popBack() {
//         if(nums.empty()) return -1;
//         int ret= nums[nums.size()-1];
//         nums.pop_back();
//         return ret;
//     }

// };

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */

// option 2 maintain two deque ，一個是前半段，另一個是後半段
//  提供兩個函數使得能在常數時間獲取中間數字
class FrontMiddleBackQueue
{
private:
    deque<int> first, second;
    void a2b()
    {
        if (first.size() <= second.size())
            return;
        second.push_front(first.back());
        first.pop_back();
    }
    void b2a()
    {
        if (second.size() <= first.size() + 1)
            return;
        first.push_back(second.front());
        second.pop_front();
    }

public:
    FrontMiddleBackQueue()
    {
    }

    void pushFront(int val)
    {
        first.push_front(val);
        a2b();
    }

    void pushMiddle(int val)
    {
        first.push_back(val);
        a2b();
    }

    void pushBack(int val)
    {
        second.push_back(val);
        b2a();
    }

    int popFront()
    {
        if (first.empty() && second.empty())
            return -1;
        int ans;
        if (first.empty())
        {
            ans = second.front();
            second.pop_front();
        }
        else
        {
            ans = first.front();
            first.pop_front();
            b2a();
        }
        return ans;
    }

    int popMiddle()
    {
        if (first.empty() && second.empty())
            return -1;
        int ans;
        if (first.size() == second.size())
        {
            ans = first.back();
            first.pop_back();
        }
        else
        {
            ans = second.front();
            second.pop_front();
        }
        return ans;
    }

    int popBack()
    {
        if (first.empty() && second.empty())
            return -1;
        int ans = second.back();
        second.pop_back();
        a2b();
        return ans;
    }
};
