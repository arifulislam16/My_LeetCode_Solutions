class Solution {
public:
    int minimumTime(int n, vector<vector<int>>&edge, vector<int>& time) {
       vector<int>ind(n+1,0),cost(n+1,0);
       for(int i=0;i<n;i++){
           cost[i+1]=time[i];
       }
       vector<int>g[n+1];
       for(vector<int>e:edge){
           int u=e[0],v=e[1];
           g[u].push_back(v);
           ind[v]+=1;
       }
       queue<int>q;
       for(int i=1;i<=n;i++){
           if(ind[i]==0){q.push(i);}
       }
       
       while(q.size()){
           int u=q.front();q.pop();
           for(int v:g[u]){
               ind[v]-=1;
               cost[v]=max(cost[v],cost[u]+time[v-1]);
             //  cout<<v<<" "<<cost[v]<<"\n";
               if(ind[v]==0){q.push(v);}
           }
       }
       int mx=-1;for(int i=1;i<=n;i++){mx=max(mx,cost[i]);}
       return mx;
    }
};