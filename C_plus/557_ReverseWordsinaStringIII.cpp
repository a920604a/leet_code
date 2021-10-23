class Solution {
public:
    string reverseWords(string s) {
        
        // option 1 in-place
        int l = 0, r= 0;
        while(r<s.size()){
            if(s[r]==' '){
                reverse(s.begin() + l, s.begin() +r);
                l = r+1;
            }
            r++;
        }
        reverse(s.begin() + l, s.begin() +r);
        return s;


        // option 2 
        int n= s.size(), l =0, r=n-1;
        while(l<n && s[l]==' ') l++;
        while(r>l && s[r]==' ') r--;
        string ret;
        
        for(int i=l;i<=r;++i){
            if(s[i]==' '){
                string temp = s.substr(l, i-l);
                while(s[i]==' ') i++;
                reverse(temp.begin(), temp.end());
                ret+= temp + ' ';
                l=i;
            }
        }
        string temp = s.substr(l, r+1-l);
        reverse(temp.begin(), temp.end());
        ret += temp;
        return ret;
    }
};