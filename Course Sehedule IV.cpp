class Solution {
public:
int dfs(int u,int tar,vector<int>g[],
vector<vector<int>>&dp){
    if(u==tar){return dp[u][tar]=1;}
    else if(dp[u][tar]!=-1){return dp[u][tar];}
    int ans=0;
    for(int v:g[u]){
      if(dfs(v,tar,g,dp)){ans=1;break;}
    }
    return dp[u][tar]=ans;
}
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& que) {
    vector<vector<int>>dp(n,vector<int>(n,-1));
    vector<int>g[n+1];
    for(vector<int>&e:pre){
        int u=e[0],v=e[1];
        g[u].push_back(v);
    }
     int k=0;
     vector<bool>res(que.size(),false);
     for(vector<int>&e:que){
         int u=e[0],v=e[1];
         res[k++]=dfs(u,v,g,dp);
     }
     return res;
    }
};