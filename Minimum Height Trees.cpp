class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.size()==0){return {0};}
     vector<int>g[n+1];
     int ind[n+1];
     memset(ind,0,sizeof(ind));
     for(vector<int>p : edges){
         int u=p[0],v=p[1];
         g[u].push_back(v);
         g[v].push_back(u);
         ind[v]+=1;
         ind[u]+=1;
     }
     queue<int>q;
     vector<int>res;
     for(int i=0;i<n;i++){
         if(ind[i]==1){q.push(i);}
     }
     while(q.size()){
         int sz=q.size();
         cout<<"Before clear : ";
         for(auto&i:res){cout<<i<<" ";}
         cout<<"\n" ;
         res.clear();
         while(sz--){
             int u=q.front();q.pop();
             res.push_back(u);
             for(int v:g[u]){
                 ind[v]-=1;
                 if(ind[v]==1){q.push(v);}
             }
         }
     }
     return res;
    }
};