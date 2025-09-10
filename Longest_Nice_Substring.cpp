class Solution {
public:
string get(string s){
  if(s.size()<2){return "";}
   bool low[26],up[26];
   memset(low,false,sizeof(low));
   memset(up,false,sizeof(up));
   for(char ch:s){
       if(islower(ch)){low[ch-'a']=true;}
       else{up[ch-'A']=true;}
   }
  // cout<<s<<'\n';
   for(int i=0;i<s.size();i++){
      int val=0;
       
      if(islower(s[i])){val=s[i]-'a';}
      else{val=s[i]-'A';}
      if(up[val]&&low[val]){continue;}
       string s1=get(s.substr(0,i));
       string s2=get(s.substr(i+1));
       if(s1.size()>=s2.size()){return s1;}
       return s2;
   }
   return s;
}
    string longestNiceSubstring(string s) {
          
          return get(s);
    }
};