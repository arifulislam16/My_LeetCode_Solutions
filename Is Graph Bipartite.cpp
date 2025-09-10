class Solution {
public:
bool ok(int u,bool visit[],
vector<vector<int>>&graph,int color[],int c){
    visit[u]=true;
    color[u]=c;
//    vector<int>vec=graph[u];
    for(int v:graph[u]){
        if(!visit[v]){
            if(!ok(v,visit,graph,color,1-c)){
                return false;
            }
        }
        else if(color[v]==color[u]){return false;}
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int color[n+1];
        bool visit[n+1];
        memset(visit,false,sizeof(visit));
        for(int i=0;i<n;i++){
            if(!visit[i]){
                if(!ok(i,visit,graph,color,0)){
                    return false;
                }
            }
        }
        return true;
    }
};