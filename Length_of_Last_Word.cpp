class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.size()-1;
        string tmp="";
        while(i>=0){
            if(isspace(s[i])){
                if(tmp.size()){return tmp.size();}
                tmp="";
            }
            else{
                tmp+=s[i];
            }
            i--;
        }
        return tmp.size();
    }
};