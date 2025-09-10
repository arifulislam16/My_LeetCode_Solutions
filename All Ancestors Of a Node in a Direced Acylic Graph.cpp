class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
      vector<int>g[n+1];
      int ind[n+1];
      for(int i=0;i<n;i++){ind[i]=0;}
     for(vector<int>&e:edges){
         int u=e[0],v=e[1];
         g[u].push_back(v);
         ind[v]+=1;
     }
      
      set<int>s[n];
      queue<int>q;
      for(int i=0;i<n;i++){if(ind[i]==0){q.push(i);}}
      while(q.size()){
          int u=q.front();q.pop();
          for(int v:g[u]){
              ind[v]-=1;
              if(ind[v]==0){q.push(v);}
              s[v].insert(u);
              for(int nxt:s[u]){s[v].insert(nxt);}
          }
      }
      vector<vector<int>>res(n);
      for(int i=0;i<n;i++){
          for(int nxt:s[i]){res[i].push_back(nxt);}
      }
      return res;
    }
};