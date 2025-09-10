class Solution {
public:
int getpar(int a,int par[]){
    int tmp=a;
    while(par[tmp]!=tmp){
        tmp=par[par[tmp]];
    }
    return tmp;
}
void getunion(int pa,int pb,int par[],int size[]){
    if(size[pa]>size[pb]){
        size[pa]+=size[pb];
        par[pb]=pa;
    }
    else{
        size[pb]+=size[pa];
        par[pa]=pb;
    }
    return ;
}
void dfs(int u,vector<int>g[],bool visit[]){
    visit[u]=true;
    for(int v:g[u]){
        if(!visit[v]){
            dfs(v,g,visit);
        }
    }
    return ;
}
    int findCircleNum(vector<vector<int>>&mat) {
        int n=mat.size();
       bool visit[n+1];
        vector<int>g[n+1];
        for(int i=0;i<n;i++){
            visit[i]=false;
            for(int j=0;j<n;j++){
                if(mat[i][j]){g[i].push_back(j);g[j].push_back(i);}
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(!visit[i]){
                ans+=1;
                dfs(i,g,visit);
            }
        }
        return ans;
    }
};