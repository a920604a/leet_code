class Solution
{
public:
    vector<int> threeEqualParts(vector<int> &arr)
    {
        int countNumberOfOnes = 0;
        for (int a : arr)
            countNumberOfOnes += a;
        if (countNumberOfOnes == 0)
            return {0, (int)arr.size() - 1};
        if (countNumberOfOnes % 3 != 0)
            return {-1, -1};

        int k = countNumberOfOnes / 3;
        int i, start, end, mid;
        int size = arr.size();
        // 1. find the first 1 in the array , store start variable
        for (i = 0; i < size; ++i)
        {
            if (arr[i] == 1)
                break;
        }
        start = i;

        // 2. find (k+1)th 1 in the array
        int count1 = 0;
        for (i = 0; i < size; ++i)
        {
            if (arr[i] == 1)
            {
                count1++;
            }
            if (count1 == k + 1)
                break;
        }
        mid = i;
        // 3. find (2*k+1)th 1 in the array
        count1 = 0;
        for (i = 0; i < size; ++i)
        {
            if (arr[i] == 1)
            {
                count1++;
            }
            if (count1 == 2 * k + 1)
                break;
        }
        end = i;

        // 4. Match all values till the end of the array
        while (end < size && arr[start] == arr[mid] && arr[mid] == arr[end])
        {
            start++;
            mid++;
            end++;
        }
        if (end == size)
            return {start - 1, mid};
        return {-1, -1};
    }
};