class Solution {
public:
bool ok(vector<int>&a,vector<int>&b){
    if(a[0]==b[0]||a[1]==b[1]){return true;}
    return false;
}
void dfs(int u,vector<int>g[],bool visit[],int &tmp){
    tmp+=1;
    visit[u]=true;
    for(int v:g[u]){
        if(!visit[v]){
            dfs(v,g,visit,tmp);
        }
    }
    return ;
}
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        bool visit[n+1];
        for(int i=0;i<=n;i++){visit[i]=false;}
        vector<int>g[n+1];
        for(int i=0;i<stones.size();i++){
            for(int j=i+1;j<stones.size();j++){
                if(ok(stones[i],stones[j])){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(!visit[i]){
                int tmp=0;
                dfs(i,g,visit,tmp);
                res+=tmp-1;
            }
        }
        return res;
    }
};