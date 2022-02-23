---
title: Sort
tags:  
    - sorting
    - Binary Search
categories: 
    - CS
    - Algorithm
comments: false
---


## complexity

| case         | Bubble sort | insertion sort | selection sort | merge sort | quick sort | Radix Sort |
| ------------ | ----------- | -------------- | -------------- | ---------- | ---------- | ---------- |
| best case    | $N$         | $N$            | $N^2$          | $NlogN$    | $NlogN$    |      kN      |
| average case | $N^2$       | $N^2$          | $N^2$          | $NlogN$    | $NlogN$    |            |
| worst case   | $N^2$       | $N^2$          | $N^2$          | $NlogN$    | $N^2$      |            |
| Memory       | 1       | 1           | 1        | Depends    | logN   |            |


## implement
```c++
// #include <stdlib>
#include <iostream>
#include <vector>
using namespace std;

void swap(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}
// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
void SelectSort(vector<int> &nums)
{

    //每輪確保最小值在前面 best case O(n^2)   可以是 stable
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        int min_idx = i;
        for (int j = i + 1; j < nums.size(); ++j)
        {

            if (nums[min_idx] > nums[j])
            {
                min_idx = j;
            }
        }
        swap(nums[min_idx], nums[i]);
    }
}
void InsertSort(vector<int> &nums)
{
    // 前i 個元素是已排序過的，插入第i+1 個元素 best case O(n) stable
    for (int i = 1; i < nums.size(); ++i)
    {

        int key = nums[i];
        int j = i - 1;
        while (j > -1 && nums[j] > key)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}
void BubbleSort(vector<int> &nums)
{

    // 每輪確保最大值在最後 best case O(n) stable
    for (int i = 0; i < nums.size(); ++i)
    {

        for (int j = 0; j < nums.size() - i - 1; j++)
        {
            if (nums[j + 1] < nums[j])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

int Partition(vector<int> &nums, int l, int r)
{
    int pivot = nums[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {

        if (nums[j] < pivot)
        {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    i++;
    swap(nums[r], nums[i]);

    return i;
}
void QuickSort(vector<int> &nums, int l, int r)
{
    // O(nlogn) avg case, worse case O(n^2)
    // internal sortting , in-place
    // unstable
    // preferred for arrays
    // preorder
    if (l < r)
    {
        int pivot = Partition(nums, l, r);
        QuickSort(nums, l, pivot - 1);
        QuickSort(nums, pivot + 1, r);
    }
}

void Merge(vector<int> &nums, int l, int mid, int r)
{
    if(l>=r) return;
    vector<int> left(nums.begin() + l, nums.begin() + mid+1);
    vector<int> right(nums.begin() + mid+1, nums.begin() + r + 1);

    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
            nums[k++] = left[i++];
        else
            nums[k++] = right[j++];
            
    }
    while (i < left.size())
        nums[k++] = left[i++];
    while (j < right.size())
        nums[k++] = right[j++];


    // option 2
    // left.push_back(INT_MAX);
    // right.push_back(INT_MAX);
    // int j=0, k=0;
    // for(int i=l ;i<=r ;++i){
    //     if(left[j]<right[k])  nums[i] = left[j++];
    //     else nums[i] = right[k++];
    // }
}
void MergeSort(vector<int> &nums, int l, int r)
{
    // external sort , worse cse and avg case O(nlogn)
    // not in place , need eatra space
    // stable
    // preferred for linked list

    if (l < r)
    {

        int mid = l + (r - l) / 2;
        MergeSort(nums, l, mid);
        MergeSort(nums, mid + 1, r);
        Merge(nums, l, mid, r);
    }
}

int main()
{

    // void (*f[3])(vector<int> &) = {SelectSort, InsertSort, BubbleSort};
    void (*f[1])(vector<int> &) = {SelectSort};
    for (int i = 0; i < 1; i++)
    {

        vector<int> test = {5, 1, 2, 32, 4};
        vector<int> test1 = {10, 1, 2, 2, 4};
        vector<int> test2 = {5, 4, 3, 2, 1, 0};
        for (int i : test1)
            cout << i << " ";
        cout << endl;
        (*f[i])(test1);
        for (int i : test1)
            cout << i << " ";
        cout << endl;
    }

    void (*fp[1])(vector<int> &, int, int) = {MergeSort};
    for (int i = 0; i < 1; ++i)
    {
        vector<int> test3 = {3, 2, 1, 5, 6, 4};
        for (int i : test3)
            cout << i << " ";
        cout << endl;

        (*fp[i])(test3, 0, test3.size() - 1);
        for (int i : test3)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
```