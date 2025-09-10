class Solution {
public:
bool ok(int u,vector<int>g[],bool visit[],
int color[],int c){
    visit[u]=true;
    color[u]=c;
    for(int v:g[u]){
        if(!visit[v]){
            if(!ok(v,g,visit,color,1-c)){
                return false;
            }
        }
        else if(color[v]==color[u]){
            return false;
        }
    }
    return true;
}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int color[n+1];
        bool visit[n+1];
        for(int i=0;i<=n;i++){
            color[i]=-1;
            visit[i]=false;
        }
        vector<int>g[n+1];
        for(vector<int>e:dislikes){
            int u=e[0],v=e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            if(!visit[i]){
                if(!ok(i,g,visit,color,1)){
                    return false;
                }
            }
        }
        return true;
    }
};