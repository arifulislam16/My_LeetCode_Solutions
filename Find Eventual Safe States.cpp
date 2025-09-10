class Solution {
public:

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>g[n+1];
        int out[n];memset(out,0,sizeof(out));
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                int u=i,v=graph[i][j];
                out[u]+=1;
                g[v].push_back(u);
            }
        }
        vector<int>res;
        queue<int>q;for(int i=0;i<n;i++){
            if(out[i]==0){q.push(i);}
        }
        while(q.size()){
            int u=q.front();q.pop();
            res.push_back(u);
            for(int v:g[u]){
                out[v]-=1;
                if(out[v]==0){q.push(v);}
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};