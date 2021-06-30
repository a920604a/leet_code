class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {

        // option 1 O(n) times
        // if(arr.size()<3) return false;
        // int l=0, r=arr.size()-1;
        // while(l<arr.size() && arr[l]<arr[l+1]) l++;
        // while(r>0 && arr[r-1]>arr[r]) r--;
        // return (r==arr.size()-1 || l==0)?false:r==l;

        // option 2  O(n) times
        // int i=0, n=arr.size();
        // while(i<n-1 && arr[i]<arr[i+1]) i++;
        // if(i==0 || i==n-1) return false;
        // while(i<n-1 && arr[i]>arr[i+1]) i++;
        // return i==n-1;

        // option 3 binary search O(nlogn) average time
        // [3,5,3,2,0] 會有bug
        int n = arr.size();
        if (n < 3)
            return false;

        // find 山峰候選點
        int found = binarySearch(arr, 0, n - 1);
        // int found = bSearch(arr,n);
        cout << found << endl;
        if (found == -1)
            return false;

        // 驗證其合法性，檢查山峰候選點左右是否有為斜坡單調遞增、單調遞減。
        for (int i = 0; i < found; i++)
        {
            if (arr[i] >= arr[i + 1])
            {
                return false;
            }
        }
        for (int i = n - 1; i > found; i--)
        {
            if (arr[i] >= arr[i - 1])
            {
                return false;
            }
        }
        return true;
    }

    int binarySearch(vector<int> &arr, int l, int r)
    {
        int val, prev, next;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            cout << mid << endl;
            if (mid - 1 >= 0 && mid + 1 < arr.size())
            {
                val = arr[mid];
                prev = arr[mid - 1];
                next = arr[mid + 1];
                if (val > prev && val > next)
                {
                    return mid;
                }
                else if (val > prev && next > val)
                    l = mid + 1;
                else
                    r = mid; // 防止 [3,5,3,2,0] mid = 2  直接變成0 ，(0+2)/2 = 1 , 而不要使他成為 (0+1)/2=0
            }
            else
                break;
        }
        return -1;
    }
};