class Solution {
public:
bool cnt(string& s,int b,int e,int d){
    if(b==e){return true;}
    if(b>e){return true;}
    if(s[b]==s[e]){
        return cnt(s,b+1,e-1,d);
    }
    else if(d){
        return cnt(s,b+1,e,d-1)||cnt(s,b,e-1,d-1);
    }
    else{return false;}
}
    bool validPalindrome(string s) {
        return cnt(s,0,s.size()-1,1);
    }
};