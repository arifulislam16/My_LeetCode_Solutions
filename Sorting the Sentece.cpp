class Solution {
public:

//is2 sentence4
struct comp{
bool operator()(const string&s1,const string&s2)const{
    int d1=s1[s1.size()-1]-'0';
    int d2=s2[s2.size()-1]-'0';
    return d1<d2;
}
};
    string sortSentence(string s) {
        //sort(s.begin(),s.end(),comp);
        vector<string>res;
        string tmp="";
        for(int i=0;i<s.size();i++){
            if(isspace(s[i])){
                res.push_back(tmp);
                tmp="";
                continue;
            }
            tmp+=s[i];
        }
        res.push_back(tmp);
       sort(res.begin(),res.end(),comp());
       //for(string tmp:res){cout<<tmp<<'\n';}
       //return "";
       string ans="";
       for(string str:res){
           ans+=str;
           ans.pop_back();
           ans+=" ";
       }
       ans.pop_back();
       return ans;
    }
};