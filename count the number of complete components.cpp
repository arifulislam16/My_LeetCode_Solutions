class Solution {
public:
void dfs(int u,vector<int>g[],vector<int>&visit,vector<int>&ind,bool& ok,int tar,vector<int>&ans){
    visit[u]=true;
    ans.push_back(u);
    for(int v:g[u]){
        if(!visit[v]){
            if(ind[v]!=tar){ok=false;}
            dfs(v,g,visit,ind,ok,tar,ans);
        }
    }
    return ;
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
      vector<int>g[n+1],ind(n+1,0),visit(n+1,0);
      for(vector<int>e:edges){
          int u=e[0],v=e[1];
          g[u].push_back(v);
          g[v].push_back(u);
          ind[u]+=1;
          ind[v]+=1;
      }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(visit[i]==0){
                bool ok=true;
                int tar=ind[i];
                vector<int>ans;
                dfs(i,g,visit,ind,ok,tar,ans);
                int sz=ans.size();
                ok=true;
                for(int x:ans){
                    if(ind[x]!=sz-1){ok=false;break;}
                }
                if(ok){cnt++;}
            }
        }
        return cnt;
      
    }
};