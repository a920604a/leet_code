---
title: Queue
tags:  
    - queue
categories: 
    - CS
    - Data Structure
comments: false
---


### Queue  可以array 、 linked list實現

| algorithm | Average | Worst case |
| --------- | ------- | ---------- |
| space     | O(n)    | O(n)       |
| search    | O(n)    | O(n)       |
| insert    | O(1)    | O(1)       |
| delete    | O(1)    | O(1)       |


* 常用方法 push pop front back size empty swap emplace
* back() front() push_back() pop_front()
### priority_queue 用vector 實作 但資料結構是 max-heap
* 常用方法 push pop top size empty swap emplace
* front() push_back() pop_back()
* heap 插入刪除元素時間 O(logn)

### deque
* 存取方法 deq.at(i)/deq[i] front back
* 容量 size empty resize max_size shrink_to_fit
* 修改器 push_back/emplace_back pop_back push_front/emplace_front pop_front insert/emplace clear erase swap 
* 疊代 begin end rbegin rend cbegin cend crbegin crend

## implement code
```c++
#include <iostream>
#include <stack>
using namespace std;

class QueueStack
{
private:
    stack<int> sta;

public:
    QueueStack() {}

    int front();
    int back();
    int size();
    bool empty();
    void pop();
    void push(int x);
};

int QueueStack::front()
{
    stack<int> tmp;
    while (!sta.empty())
    {
        tmp.push(sta.top());
        sta.pop();
    }
    int ret = tmp.top();
    while (!tmp.empty())
    {
        sta.push(tmp.top());
        tmp.pop();
    }
    return ret;
}

int QueueStack::back()
{
    if (sta.empty())
    {
        std::cout << "The queue is empty" << endl;
        return -1;
    }
    return sta.top();
}

int QueueStack::size()
{
    return sta.size();
}

bool QueueStack::empty()
{
    return sta.empty();
}

void QueueStack::pop()
{
    if (sta.empty())
    {
        std::cout << "The queue is empty" << endl;
        return;
    }

    stack<int> tmp;
    while (!sta.empty())
    {
        tmp.push(sta.top());
        sta.pop();
    }
    int ret = tmp.top();
    tmp.pop();
    while (!tmp.empty())
    {
        sta.push(tmp.top());
        tmp.pop();
    }
    // return ret;
}

void QueueStack::push(int x){
    sta.push(x);
}

void print(QueueStack q){
    stack<int> tmp;
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        tmp.push(q.front());
        q.pop();
    }
    cout<<endl;
}
int main(){
    QueueStack q;
    q.pop();
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.pop();
    print(q);
}

```

