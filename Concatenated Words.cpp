class Solution {
public:
unordered_map<string,int>mp;
bool dfs(int i,string&s,vector<int>&dp){
    if(i>=s.size()){return true;}
    else if(dp[i]!=-1){return dp[i];}
    bool ok=false;
    if(i==0){
        for(int j=1;j<s.size();j++){
            string pre=s.substr(0,j);
            if(mp[pre]&&dfs(j,s,dp)){
                ok=true;break;
            }
        }
    }
    else {
        for(int j=i;j<s.size();j++){
            string pre=s.substr(i,j-i+1);
            if(mp[pre]&&dfs(j+1,s,dp)){ok=true;break;}
        }
    }
    return (ok)?dp[i]=1:dp[i]=0;
}
struct comp{
bool operator()(const string&s1,const string&s2)const{
    return s1.size()<s2.size();
}
};
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
     for(string str:words){
         mp[str]=1;
     }
     sort(words.begin(),words.end(),comp());
     
   //  cout<<"\n";
     vector<string>res;
     for(int i=words.size()-1;i>=0;i--){
         mp[words[i]]=0;
         vector<int>dp(words[i].size()+1,-1);
     //    cout<<words[i]<<" \n";
         if(dfs(0,words[i],dp)){res.push_back(words[i]);}
     }
     return res;
    }
};