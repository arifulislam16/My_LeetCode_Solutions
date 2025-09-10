class Solution {
public:
bool ok(string&s){
    int b=0,e=s.size()-1;
    while(b<e){
        if(s[b]!=s[e]){return false;}
        b++;
        e--;
    }
    return true;

}
    string firstPalindrome(vector<string>& words) {
        string res="";
        for(string str:words){
            if(ok(str)){
               return str;
            }
        }
        return res;
    }
};