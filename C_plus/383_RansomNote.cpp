class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        // option 1
        //         if(ransomNote.size() > magazine.size()) return false;
        //         vector<int> vec(26,0); // you can also use map

        //         for(int a:magazine) vec[a-'a']++;
        //         for(int a:ransomNote) vec[a-'a']--;
        //         for(int a:vec){
        //             if(a<0) return false;
        //         }
        //         return true;

        // option 2
        map<char, int> m;
        if (ransomNote.size() > magazine.size())
            return false;
        for (char a : magazine)
            m[a]++;
        for (char a : ransomNote)
        {
            m[a]--;
            if (m[a] < 0)
                return false;
        }
        return true;
    }
};