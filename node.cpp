define pb push_back
const int mod=1e9+7;
int cnt(int u,vector<int>g[],int n,int dp[]){
  if(u==n){return 1;}
  else if(dp[u]!=-1){return dp[u];}
  int ans=0;
  for(auto &v:g[u]){
    ans=(ans%mod+cnt(v,g,n,dp)%mod)%mod;
  }
  return dp[u]=ans%mod;
  
}
int main(){
  int n,m;cin>>n>>m;vector<int>g[n+1];
  for(int i=0;i<m;i++){
    int u,v;cin>>u>>v;g[u].pb(v);
  }
  int dp[n+1];memset(dp,-1,sizeof(dp));
  cout<<cnt(1,g,n,dp)%mod;
  
