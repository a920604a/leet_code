class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        // option 1 O(n)
        // two pointer
        // int l =0, r = numbers.size()-1;
        // while(l<r){
        //     if(target == numbers[l] + numbers[r]) return {l+1,r+1};
        //     else if(target >numbers[l] + numbers[r]) l++;
        //     else if(target <numbers[l] + numbers[r]) r--;
        // }
        // return {};

        //option 2  O(nlogn)
        // map

        map<int, int> m;
        for (int i = 0; i < numbers.size(); ++i)
        {

            if (m.find(target - numbers[i]) != m.end())
                return {m[target - numbers[i]] + 1, i + 1};
            m[numbers[i]] = i;
        }
        return {};
    }
};