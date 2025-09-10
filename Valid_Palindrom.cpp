class Solution {
public:
bool ispal(string& s){
    int b=0,e=s.size()-1;
    while(b<=e){
        if(s[b]!=s[e]){return false;}
        b++,e--;
    }
    return true;
}
    bool isPalindrome(string s) {
        string res="";
        int i=0;
        string tmp="";
        while(i<s.size()){
            if(isspace(s[i])||ispunct(s[i])){
                if(tmp.size()){
                    res+=tmp;
                }
                tmp="";
            }
            else{
                tmp+=tolower(s[i]);
            }
            i++;
        }
        if(tmp.size()){res+=tmp;}
        cout<<res<<"\n";
        return ispal(res);

       
    }
};