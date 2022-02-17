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
