class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        // option 0
        // binary search O(nlogn) time
        // 選定 索引為 i 的數字 ，在用binary search 找 另一個數字使總和為target
        int n = numbers.size();
        
        for(int i=0;i<n;++i){
            int sum = target - numbers[i], l= i+1, r = n;
            
            while(l<r){
                int mid = l + (r-l)/2;
                if(numbers[mid] == sum) return {i+1, mid+1};
                else if(numbers[mid] < sum) l = mid+1;
                else  r = mid;
                
            }
        }
        return {};

        // option 1 O(n)
        // two pointer
        // int l =0, r = numbers.size()-1;
        // while(l<r){
        //     if(target == numbers[l] + numbers[r]) return {l+1,r+1};
        //     else if(target >numbers[l] + numbers[r]) l++;
        //     else if(target <numbers[l] + numbers[r]) r--;
        // }
        // return {-1,-1};



        //option 2  O(n)
        // map

        unordered_map<int,int> m;
        for (int i = 0; i < numbers.size(); ++i)
        {

            if (m.find(target - numbers[i]) != m.end())
                return {m[target - numbers[i]] + 1, i + 1};
            m[numbers[i]] = i;
        }
        return {};
    }
};