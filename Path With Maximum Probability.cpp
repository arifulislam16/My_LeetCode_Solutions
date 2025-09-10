class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>>g[n+1];
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        double wt=succProb[i];
        g[u].push_back({v,wt});
        g[v].push_back({u,wt});
    }
    bool visit[n+1];
    memset(visit,false,sizeof(visit));
    double dis[n+1];
   
    for(int i=0;i<=n;i++){dis[i]=0.0;}
     dis[start]=1.0;
    priority_queue<pair<double,int>>pq;
    pq.push({(double)1.0,start});
    while(pq.size()){
        pair<double,int>tmp=pq.top();pq.pop();
        double d=tmp.first;
        int u=tmp.second;
        if(u==end){return d;}
    ///   if(visit[u]){continue;}
  //      visit[u]=true;
        for(pair<int,double>&i:g[u]){
            int v=i.first;
            double wt=i.second;
            if(dis[v]<dis[u]*wt){
                dis[v]=dis[u]*wt;
                pq.push({dis[v],v});
            }
//            pq.push({d*wt*1.0,v});
        }
    }
    return 0.0;
    }
};