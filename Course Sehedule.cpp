class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int>g[n+1];
        int ind[n];
        memset(ind,0,sizeof(ind));
        for(vector<int>v:prerequisites){
            int p=v[1],q=v[0];
            // p - > q;
            ind[q]+=1;
            g[p].push_back(q);
        }
        queue<int>q;
        bool ok=false;
        for(int i=0;i<n;i++){
            if(ind[i]==0){ok=true;q.push(i);}
        }
        if(!ok){return false;}
        int cnt=0;
        bool visit[n+1];
        memset(visit,false,sizeof(visit));
        while(q.size()){
            int u=q.front();q.pop();
            //visit[u]=true;
            cnt+=1;
            for(auto&v:g[u]){
               ind[v]-=1;
               if(ind[v]==0){q.push(v);}
            }
        }
        if(cnt==n){return true;}
        return false;
    }
};