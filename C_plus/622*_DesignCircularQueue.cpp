// option 1
class MyCircularQueue
{
private:
    vector<int> data;
    int size;

public:
    MyCircularQueue(int k)
    {
        size = k;
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        data.emplace_back(value);
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        data.erase(data.begin());
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return data.front();
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        return data.back();
    }

    bool isEmpty()
    {
        return data.empty();
    }

    bool isFull()
    {
        return data.size() >= size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// option 1
class MyCircularQueue
{
private:
    vector<int> data;
    int size;

public:
    MyCircularQueue(int k)
    {
        size = k;
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        data.emplace_back(value);
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        data.erase(data.begin());
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return data.front();
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        return data.back();
    }

    bool isEmpty()
    {
        return data.empty();
    }

    bool isFull()
    {
        return data.size() >= size;
    }
};

// option 2
class MyCircularQueue
{
private:
    vector<int> data;
    int size, front, rear;

public:
    MyCircularQueue(int k)
    {
        size = k;
        front = 0;
        rear = 0;
        data.resize(k, -1);
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        data[rear] = value;
        rear = (rear + 1) % size;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        data[front] = -1;
        front = (front + 1) % size;
        return true;
    }

    int Front()
    {
        return data[front];
    }

    int Rear()
    {
        return data[(size + rear - 1) % size];
    }

    bool isEmpty()
    {
        return data[front] == -1 && front == rear;
    }

    bool isFull()
    {
        return data[front] != -1 && front == rear;
    }
};
