class Solution {
public:
    string generateTheString(int n) {
        if(!(n&1)){
            string res="";
            for(int i=0;i<n-1;i++){
                res+='a';
            }
            res+='b';
            return res;
        }
        else{
            string res="";
            for(int i=0;i<n;i++){
                res+='a';
            }
            return res;
        }
    }
};