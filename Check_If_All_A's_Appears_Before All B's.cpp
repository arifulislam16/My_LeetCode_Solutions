class Solution {
public:
    bool checkString(string s) {
        bool noa=true;
        for(char ch:s){
            if(ch=='a'){noa=false;break;}
        }
        if(noa){return true;}
        int pos=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b'){pos=i;break;}
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                if(pos!=-1&&i>pos){return false;}
            }
        }
        int cnta=0,cntb=0;
        for(char ch:s){
            if(ch=='a'){cnta+=1;}
            else{cntb+=1;}
        }
        if(cnta==s.size()||cntb==s.size()){return true;}
        return true;
    }
};