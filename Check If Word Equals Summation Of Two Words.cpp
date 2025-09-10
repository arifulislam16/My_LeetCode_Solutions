class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
         string f="",s="",t="";
         unordered_map<char,char>mp;
         for(int i=0;i<26;i++){
             mp[i+'a']=char(i+'0');
            // cout<<mp[i+'a']<<"\n";
         }
         for(char ch:firstWord){f+=char(mp[ch]);}
         for(char ch:secondWord){s+=char(mp[ch]);}
         for(char ch:targetWord){t+=char(mp[ch]);}
         cout<<f<<'\n';
        while(f.size()&&f[0]=='0'){f.erase(f.begin());}
        while(s.size()&&s[0]=='0'){s.erase(s.begin());}
        while(t.size()&&t[0]=='0'){t.erase(t.begin());}
        int fval=0,sval=0,tval=0;
        for(int i=0;i<f.size();i++){fval=(fval*10)+(f[i]-'0');}
        for(int i=0;i<s.size();i++){sval=(sval*10)+(s[i]-'0');}
        for(int i=0;i<t.size();i++){tval=(tval*10)+(t[i]-'0');}
        return fval+sval==tval;
        cout<<f;
         return false;
    }
};