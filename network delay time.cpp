class Solution {
public:
int max(int a,int b){return (a>b)?a:b;}
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>g[n+1];
        for(vector<int>e:times){
            int u=e[0],v=e[1],wt=e[2];
            g[u].push_back({v,wt});
        }
       priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
       int dis[101];
       for(int i=0;i<=n;i++){dis[i]=1e9;}
       dis[k]=0;
       pq.push({dis[k],k});
       while(pq.size()>0){
           vector<int>tmp=pq.top();pq.pop();
           int u=tmp[1];
           for(pair<int,int>p:g[u]){
               int v=p.first,wt=p.second;
               if(dis[v]>dis[u]+wt){
                   dis[v]=dis[u]+wt;
                   pq.push({dis[v],v});
               }
           }
       }
       int res=0;for(int i=1;i<=n;i++){if(dis[i]==1e9){return -1;}else{res=max(res,dis[i]);}}
       return res;
    }
};