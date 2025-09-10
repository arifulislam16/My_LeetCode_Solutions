class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res=0;
        for(string str:words){
            if(str.size()>=pref.size()){
    string tmp=str.substr(0,pref.size());
    if(tmp==pref){res+=1;}
            }
        }
        return res;
    }
};