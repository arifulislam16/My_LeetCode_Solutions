class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<pair<int,int>>g[n+1];
       for(vector<int>e:flights){
           int u=e[0],v=e[1],wt=e[2];
           g[u].push_back({v,wt});  
       }   
       int dis[n+1],step[n+1];
       for(int i=0;i<=n;i++){dis[i]=step[i]=1e9;}
       dis[src]=0;
       step[src]=0;
       set<vector<int>>st;
       
       st.insert({dis[src],0,src});
       while(st.size()>0){
           vector<int>tmp=*(st.begin());st.erase(st.begin());
           int d=tmp[0],stp=tmp[1],u=tmp[2];
        
           if(stp>step[u]||stp>k+1){continue;}
           step[u]=stp;
           if(u==dst){return d;}
           for(auto& [nxt,cost]:g[u]){
               st.insert({d+cost,stp+1,nxt});
           }
       } 
       return -1;
    }
};