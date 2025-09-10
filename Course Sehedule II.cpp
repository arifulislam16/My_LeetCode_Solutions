class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

     int n=numCourses;
     vector<int>g[n+1];
     int ind[n+1];
     memset(ind,0,sizeof(ind));
     for(vector<int>v:prerequisites){
         int p=v[1],q=v[0];
         g[p].push_back(q);
         // p -> q;
         ind[q]+=1;
     }
     queue<int>q;
     for(int i=0;i<n;i++){
         if(ind[i]==0){q.push(i);}
     }
     vector<int>res;
     int cnt=0;
     while(q.size()){
         int u=q.front();
         cnt+=1;
         q.pop();
         res.emplace_back(u);
         for(int v:g[u]){
             ind[v]-=1;
             if(ind[v]==0){
                 q.push(v);
             }
         }
     }
     if(cnt==n){return res;}

     return {};
    }
};