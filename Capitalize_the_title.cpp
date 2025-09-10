class Solution {
public:
string get(string &s){
    string tmp="";
    if(s.size()==1){
        tmp+=tolower(s[0]);
        return tmp;
    }
    else if(s.size()==2){
        tmp+=tolower(s[0]);
        tmp+=tolower(s[1]);
        return tmp;
    }
    else{
        tmp+=toupper(s[0]);
        int i=1;
        while(i<s.size()){tmp+=tolower(s[i++]);}
        return tmp;
    }
}
    string capitalizeTitle(string s) {
        string tmp="";
        string res="";
        int i=0;
        while(i<s.size()){
            if(isspace(s[i])){
                if(tmp.size()){res+=get(tmp);res+=" ";}
                tmp="";
            }
            else{
                tmp+=s[i];
            }
            i++;
        }
        if(tmp.size()){res+=get(tmp);}
        return res;
    }
};