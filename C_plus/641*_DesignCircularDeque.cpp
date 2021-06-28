// option 1
// class MyCircularDeque {
// private:
//     vector<int> data;
//     int size, tail, head;
// public:
//     /** Initialize your data structure here. Set the size of the deque to be k. */
//     MyCircularDeque(int k) {
//         size=k;
//         head = 0;
//         tail = 0;

//     }

//     /** Adds an item at the front of Deque. Return true if the operation is successful. */
//     bool insertFront(int value) {
//         if(isFull()) return false;
//         data.emplace(data.begin(), value);
//         return true;
//     }

//     /** Adds an item at the rear of Deque. Return true if the operation is successful. */
//     bool insertLast(int value) {
//         if(isFull()) return false;
//         data.emplace_back(value);
//         return true;
//     }

//     /** Deletes an item from the front of Deque. Return true if the operation is successful. */
//     bool deleteFront() {
//         if(isEmpty()) return false;
//         // data.pop_front();
//         data.erase(data.begin());
//         return true;
//     }

//     /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
//     bool deleteLast() {
//         if(isEmpty()) return false;
//         data.pop_back();
//         return true;
//     }

//     /** Get the front item from the deque. */
//     int getFront() {
//         if(isEmpty()) return -1;
//         return data.front();
//     }

//     /** Get the last item from the deque. */
//     int getRear() {
//         if(isEmpty()) return -1;
//         return data.back();
//     }

//     /** Checks whether the circular deque is empty or not. */
//     bool isEmpty() {
//         return data.empty();
//     }

//     /** Checks whether the circular deque is full or not. */
//     bool isFull() {
//         return data.size()>=size;
//     }
// };

// option 2
class MyCircularDeque
{
private:
    vector<int> data;
    int front, rear, size;

public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k)
    {
        size = k;
        front = 0;
        rear = 0;
        data.resize(k, -1);
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value)
    {
        if (isFull())
            return false;
        front = (size + front - 1) % size;
        data[front] = value;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value)
    {
        if (isFull())
            return false;
        data[rear] = value;
        rear = (rear + 1) % size;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront()
    {
        if (isEmpty())
            return false;
        data[front] = -1;
        front = (front + 1) % size;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast()
    {
        if (isEmpty())
            return false;
        rear = (size + rear - 1) % size;
        data[rear] = -1;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront()
    {
        return data[front];
    }

    /** Get the last item from the deque. */
    int getRear()
    {
        return data[(size + rear - 1) % size];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty()
    {
        return front == rear && data[front] == -1;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull()
    {
        return front == rear && data[front] != -1;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */