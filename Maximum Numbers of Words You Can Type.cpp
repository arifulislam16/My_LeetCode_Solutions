class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
    unordered_map<char,int>mp;
    for(char ch:brokenLetters){
        mp[ch]+=1;
    }
    int cnt=0;
    string str="";
    for( char ch:text){
        if(isspace(ch)){
          //  cout<<str<<" ";
            bool ok=true;
            for(char c:str){
                if(mp[c]){ok=false;break;}
            }
            if(ok){cnt+=1;}
            str="";}
        else{str+=ch;}
    }
    bool ok=true;
    for(char ch:str){
        if(mp[ch]){ok=false;break;}
    }
    if(ok){cnt+=1;}
    return cnt;
    }
};