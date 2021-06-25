class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        // option 1 O(n^3)
        // can refer https://web.stanford.edu/class/cs9/sample_probs/SubarraySums.pdf
        

        int ret = 0, n = arr.size();
        for (int i = 1; i <= n; i += 2)
        { // i =1,3,5,7,9
            int k = 0;
            while (k + i - 1 < n)
            {
                int sum = accumulate(arr.begin() + k, arr.begin() + k + i, 0);
                k++;
                ret += sum;
            }
        }
        return ret;
    }
};