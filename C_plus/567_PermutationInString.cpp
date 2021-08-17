class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {

        // option 1 slide window O(n+m)
        //         unordered_map<char, int> need, window;
        //         for(char c:s1) need[c]++;
        //         int left = 0, right = 0, valid = 0;

        //         while(right < s2.size()){

        //             char c = s2[right];
        //             right++;

        //             // 更新窗口內數據
        //             if(need.count(c)){
        //                 window[c]++;
        //                 if(window[c] == need[c]) valid++;
        //             }

        //             //判斷窗口左側是否要收縮
        //             while(right - left == s1.size()){

        //                 // 找到合法子字串
        //                 if (valid == need.size()) return true;

        //                 char d = s2[left];
        //                 left++;
        //                 // 更新窗口內數據
        //                 if(need.count(d)){
        //                     if(window[d] == need[d]) valid--;
        //                     window[d]--;
        //                 }

        //             }

        //         }
        //         return false;

        // option 2 簡化移動窗口 及 option 2  O(n)
        vector<int> window(26, 0);
        vector<int> need(26, 0);
        for (char c : s1)
            need[c - 'a']++;
        for (int i = 0; i < s2.size(); ++i)
        {
            window[s2[i] - 'a']++;
            if (i >= s1.size())
                window[s2[i - s1.size()] - 'a']--;
            // 因為重新排列後長度一樣
            if (window == need)
                return true;
        }
        return false;
    }
};