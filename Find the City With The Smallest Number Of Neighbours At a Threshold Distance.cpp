class Solution {
public:
struct  comp{
bool operator()(const pair<int,int>&a,const pair<int,int>&b)const{
    if(a.first==b.first){return a.second>b.second;}
    return a.first<b.first;
}
};
void cnt(int u,int d,vector<pair<int,int>>g[],int n,vector<pair<int,int>>&res){
    vector<int>dis(n+1,1e9);
    dis[u]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({dis[u],u});
    while(pq.size()){
        pair<int,int>tmp=pq.top();pq.pop();
        int u=tmp.second;
        for(pair<int,int>next:g[u]){
            int v=next.first,wt=next.second;
            if(dis[v]>dis[u]+wt&&dis[u]+wt<=d){
                dis[v]=dis[u]+wt;
                pq.push({dis[v],v});
            }
        }
    }
    int count=0;
    for(int i=0;i<=n;i++){
        if(i!=u&&dis[i]<=d){count+=1;}
    }
    res.push_back({count,u});
}

    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        vector<pair<int,int>>g[n+1];
        for(vector<int>&i:edges){
            int u=i[0],v=i[1],wt=i[2];
            g[u].push_back({v,wt});
            g[v].push_back({u,wt});
        }
        vector<pair<int,int>>res;
        for(int i=0;i<n;i++){
            cnt(i,d,g,n,res);
        }
        sort(res.begin(),res.end(),comp());
        return res[0].second;
    }
};