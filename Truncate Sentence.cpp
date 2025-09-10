class Solution {
public:
    string truncateSentence(string s, int k) {
        string res="";
        for(char ch:s){
            if(isspace(ch)){
                res+=" ";
                k-=1;
                if(k==0){
                    res.pop_back();
                    break;
                }
                continue;
            }
            res+=ch;
        }
        return res;
    }
};