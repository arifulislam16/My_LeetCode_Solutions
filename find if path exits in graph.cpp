class Solution {
public:
bool dfs(int u,int tar,vector<int>g[],bool visit[]){
    visit[u]=true;
    if(u==tar){return true;}
    for(int v:g[u]){
        if(!visit[v]){
            if(dfs(v,tar,g,visit)){return true;}
        }
    }
    return false;
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>g[n+1];
        for(vector<int>v:edges){
            int u=v[0],nxt=v[1];
            g[u].emplace_back(nxt);
            g[nxt].emplace_back(u);
        }
        bool visit[n+1];
        memset(visit,false,sizeof(visit));
       queue<int>q;
       q.push(source);
       visit[source]=true;
       while(q.size()){
           int sz=q.size();
           while(sz-->0){
               int cur=q.front();q.pop();
                 if(cur==destination){return true;}
                    for(int v:g[cur]){
                        if(visit[v]==false){
                            q.push(v);
                            visit[v]=true;
                        }
                    }
           }
       }
       return false;
    }
};