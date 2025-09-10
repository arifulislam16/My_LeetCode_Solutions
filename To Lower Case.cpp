class Solution {
public:
    string toLowerCase(string s) {
        string res="";
        int i=0;
        while(i<s.size()){
            res+=tolower(s[i++]);
        }
        return res;
    }
};