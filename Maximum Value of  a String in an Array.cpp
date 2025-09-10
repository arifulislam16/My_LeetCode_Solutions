class Solution {
public:
int max(int a,int b){
    return (a>b)?a:b;
}
bool digit(string &s){
    bool ok=true;
    for(char ch:s){
        if(isdigit(ch)){continue;}
        else{ok=false;break;}
    }
    return ok;
}
int getd(string &s){
    while(s.size()&&s[0]=='0'){
        s.erase(s.begin());
    }
    if(s.size()==0){return 0;}
    int val=0;
    for(char ch:s){
        val=(val*10)+(ch-'0');
    }
    return val;
}
    int maximumValue(vector<string>& strs) {
        int mx=0;
        for(string str:strs){
            if(digit(str)){
                mx=max(mx,getd(str));
            }
            else{
                mx=max(mx,str.size());
            }
        }
        return mx;
    }
};