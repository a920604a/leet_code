/*
 * @Author: yuan
 * @Date: 2021-07-14 17:39:02
 * @LastEditTime: 2021-07-14 17:39:03
 * @FilePath: /leet_code/C_plus/791_CustomSortString.cpp
 */
class Solution {
public:
    string customSortString(string order, string str) {
        vector<char> vec(order.begin(), order.end());
        
        map<char, int> mp;
        for(char c: str) mp[c]++;
        string ret="", tail="";
        for(char c:vec){
            if(mp.count(c)){
                
                ret.append(mp[c], c);
            }
        }
        for(char c: str){
            vector<char>::iterator it  =std::find(vec.begin(), vec.end(), c);
            
            if(it==vec.end()) ret +=c;
        }
        cout<<ret;
        return ret;
    }
};