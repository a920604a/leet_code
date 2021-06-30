class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {

        // option 1 brute O(n)
        //         int n=arr.size()-1;

        //         for(int i=0;i<n;++i){
        //             if(i==0 || i==n-1){
        //                 if(i==0 && arr[i]>arr[i+1]) return i;
        //                 if(i==n-1 && arr[i]> arr[i-1]) return i;
        //             }
        //             else{
        //                 if( arr[i]>arr[i-1] && arr[i]>arr[i+1]) return i;
        //             }
        //         }
        //         return 0;

        // option 2 O(n) two pointer
        // int l=0,r=arr.size()-1;
        // while(l<r && arr[l]<arr[l+1]) l++;
        // while(r>0 && arr[r-1]>arr[r]) r--;
        // return r;

        // option 3 binary search O(nlogn)
        // int peak = BinarySearch(arr, arr.size());
        // return peak;

        //option 4 根據題意一定存在一個山峰
        for (int i = 1; i < arr.size() - 1; ++i)
        {
            if (arr[i] > arr[i + 1])
                return i;
        }
        return 0;
    }
    int BinarySearch(vector<int> &arr, int n)
    {
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            cout << mid << endl;
            if (mid - 1 >= 0 && mid + 1 <= n - 1)
            {
                if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                {
                    return mid;
                }
                else if (arr[mid - 1] > arr[mid] && arr[mid] > arr[mid + 1])
                    r = mid;
                // 防止l=0,r=1 (0+1)/2 = 0，l=0,r=2 (0+2)/2=1;
                else
                    l = mid + 1;
            }
            else
                break;
        }
        return -1;
    }
};