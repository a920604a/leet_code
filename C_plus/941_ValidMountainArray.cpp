class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {

        // option 1 two pointer
        if(arr.size()<3) return false;
        int l=0, r=arr.size()-1;
        while(l<arr.size() && arr[l]<arr[l+1]) l++;
        while(r>0 && arr[r-1]>arr[r]) r--;
        return (r==arr.size()-1 || l==0)?false:r==l;

        // option 2
        // int i=0, n=arr.size();
        // while(i<n-1 && arr[i]<arr[i+1]) i++;
        // if(i==0 || i==n-1) return false;
        // while(i<n-1 && arr[i]>arr[i+1]) i++;
        // return i==n-1;
    }
};