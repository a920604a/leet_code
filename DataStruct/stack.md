---
title: Stack
tags:  
    - stack
categories: 
    - CS
    - Data Structure
comments: false
---

## complexity

| algorithm | Average | Worst case |
| --------- | ------- | ---------- |
| space     | O(k)    | O(k)       |
| search    | O(n)    | O(n)       |
| insert    | O(1)    | O(1)       |
| delete    | O(1)    | O(1)       |

* 常用方法 push pop top empty size swap emplace


## implement

```c++
#include <iostream>
using namespace std;

class StackArray
{
private:
    int top;
    int capacity;
    void DoubleCapacity();

public:
    int *arr;
    StackArray() : top(-1), capacity(1)
    {
        arr = new int[capacity];
    }
    void Push(int x);
    void Pop();
    int Top();
    bool IsEmpty();
    int GetCapacity();
    int GetSize();
};

void StackArray::DoubleCapacity()
{
    int *newarr = new int[capacity * 2];

    for (int i = 0; i < capacity; ++i)
    {
        newarr[i] = arr[i];
    }
    capacity *=2;
    arr = newarr;
    delete[] newarr;
}

void StackArray::Push(int x)
{
    if(top == capacity -1)
	{
		DoubleCapacity();
	}
    arr[++top] = x;
}

void StackArray::Pop()
{
    if (IsEmpty())
    {
        std::cout << "this stack is empty" << std::endl;
        return;
    }

    top--;
}

int StackArray::Top()
{
    if (IsEmpty())
    {
        std::cout << "the stack is empty!!" << std::endl;
        return -1;
    }
    return arr[top];
}

bool StackArray::IsEmpty()
{
    return top == -1;
}

int StackArray::GetCapacity()
{
    return capacity;
}

int StackArray::GetSize()
{
    return top + 1;
}

void print(StackArray a)
{
    int *arr = a.arr;
    for (int i = 0; i < a.GetSize(); i++)
    {
        std::cout << *(arr + i) << " ";
    }
    std::cout <<"capacity is :\t"<<a.GetCapacity() << " top is :\t" << a.Top() << std::endl;
    // std::cout << std::endl;
}

int main()
{
    StackArray a;
    a.Push(8);
    a.Push(820);
    print(a);
    a.Pop();
    print(a);
    a.Push(7);
    a.Push(6);
    a.Push(5);
    a.Push(4);
    print(a);
    a.Pop();
    a.Pop();
    a.Pop();
    a.Pop();
    a.Pop();
    a.Pop();
    a.Pop();
    a.Pop();
    print(a);
}
```