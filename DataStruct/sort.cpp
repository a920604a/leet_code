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
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        for (int j = i + 1; j < nums.size(); ++j)
        {
            if (nums[i] > nums[j])
            {
                swap(nums[i], nums[j]);
            }
        }
    }
}
void InsertSort(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); ++i)
    {
        int key = nums[i];
        int j = i - 1;
        while (j > -1 && key <= nums[j])
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}
void BubbleSort(vector<int> &nums)
{

    for (int i = nums.size() - 1; i > -1; i--)
    {

        for (int j = 0; j <= i - 1; ++j)
        {
            if (nums[j + 1] < nums[j])
            {
                swap(nums[i], nums[j]);
            }
        }
    }
}

int Partition(vector<int> &nums, int l, int r)
{
    int pivot = nums[r];
    int i = l - 1;
    for (int j = l; j < r; ++j)
    {
        if (nums[j] < pivot)
        {
            // i++;
            swap(nums[j], nums[++i]);
        }
    }
    i++;
    swap(nums[i], nums[r]);
    return i;
}
void QuickSort(vector<int> &nums, int l, int r)
{

    if (l < r)
    {
        int pivot = Partition(nums, l, r);
        QuickSort(nums, l, pivot - 1);
        QuickSort(nums, pivot + 1, r);
    }
}

void Merge(vector<int> &nums, int l, int mid, int r)
{
    vector<int> left(nums.begin() + l, nums.begin() + mid + 1);
    vector<int> right(nums.begin() + mid + 1, nums.begin() + r + 1);
    left.push_back(INT_MAX);
    right.push_back(INT_MAX);

    int ll = 0, rr = 0;
    for (int i = l; i <= r; ++i)
    {
        if (left[ll] <= right[rr])
            nums[i] = left[ll++];
        else
            nums[i] = right[rr++];
    }
}
void MergeSort(vector<int> &nums, int l, int r)
{

    if (l < r)
    {
        int mid = (l + r) / 2;
        MergeSort(nums, l, mid);
        MergeSort(nums, mid + 1, r);
        Merge(nums, l, mid, r);
    }
}

int main()
{

    void (*f[3])(vector<int> &) = {SelectSort, InsertSort, BubbleSort};
    for (int i = 0; i < 3; i++)
    {

        vector<int> test = {5, 1, 2, 32, 4};
        vector<int> test1 = {1, 1, 2, 2, 4};
        vector<int> test2 = {5, 4, 3, 2, 1, 0};
        (*f[i])(test);
        for (int i : test)
            cout << i << " ";
        cout << endl;
    }

    void (*fp[2])(vector<int> &, int, int) = {QuickSort, MergeSort};
    for (int i = 0; i < 2; ++i)
    {
        vector<int> test3 = {3,2,1,5,6,4};
        (*fp[i])(test3, 0, test3.size() - 1);
        for (int i : test3)
            cout << i << " ";
        cout << endl;
    }
}