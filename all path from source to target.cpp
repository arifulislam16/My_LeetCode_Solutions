class Solution {
public:
 void dfs(int u,vector<vector<int>>&g,vector<vector<int>>&res,vector<int>&path,int tar){
    path.emplace_back(u);
    if(u==tar){res.push_back(path);path.pop_back();return ;}
    for(int v:g[u]){
        dfs(v,g,res,path,tar);
    }
    path.pop_back();
    return;
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size()        ;
        vector<vector<int>>res;
        vector<int>path;
        dfs(0,graph,res,path,n-1);
        return res;
    }
};