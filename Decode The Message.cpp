class Solution {
public:
#define f first
#define s second
    string decodeMessage(string key, string message) {
      unordered_map<char,char>mp;
      int j=0;
      for(int i=0;i<key.size();i++){
           if(isspace(key[i])){continue;}
if(mp.find(key[i])==mp.end()){
    mp[key[i]]=j+'a';
    j+=1;
}
      }

    string res="" ;
    for(char ch:message){
        if(isspace(ch)){res+=" ";}
        else{res+=mp[ch];}
    }
    return res;
      
    }
};