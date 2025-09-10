class Solution {
public:
bool ispal(string&s){
    int b=0,e=s.size()-1;
    while(b<=e){
        if(s[b++]!=s[e--]){return false;}
    }
    return true;
}
    int removePalindromeSub(string s) {
        if(ispal(s)){return 1;}
        return 2;
    }
};