class Solution {
public:
    string defangIPaddr(string address) {
        string tmp="";
        for(char ch:address){
            if(ch=='.'){
                tmp+="[.]";
            }
            else{
                tmp+=ch;
            }
        }
        return tmp;
    }
};