class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0;
        while(i<haystack.size()){
            if(i+needle.size()-1>=haystack.size()){break;}
            string tmp=haystack.substr(i,needle.size());
            if(tmp==needle){return i;}
            else{
                i++;
            }
        }
        return -1;
    }
};