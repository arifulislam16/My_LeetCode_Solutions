class Solution {
public:
const int mod=1e9+7;
int dp[40001];
int cnt(int u,int end,int dis[],vector<pair<int,int>>g[]){
    if(u==end){return dp[u]=1;}
    else if(dp[u]!=-1){return dp[u];}
    int res=0;
    for(auto&[v,wt]:g[u]){
        if(dis[u]>dis[v]){
            res=(res%mod+cnt(v,end,dis,g)%mod)%mod;
        }
    }
    return dp[u]=res%mod;
}
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        int dis[n+1];
        for(int i=0;i<=n;i++){dis[i]=2e9;}
        dis[n]=0;
        vector<pair<int,int>>g[n+1];
        for(vector<int>&e:edges){
            int u=e[0],v=e[1],wt=e[2];
            g[u].push_back({v,wt});
            g[v].push_back({u,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        //priority_queue<pair<int,int>,comp>pq;
        pq.push({dis[n],n});
        while(pq.size()){
            pair<int,int>tmp=pq.top();pq.pop();
            int u=tmp.second;
            for(auto&[v,wt]:g[u]){
                if(dis[v]>dis[u]+wt){
                    dis[v]=dis[u]+wt;
                    pq.push({dis[v],v});
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        return cnt(1,n,dis,g)%mod;
    }
};