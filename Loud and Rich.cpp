class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& graph, vector<int>& qut) {
        int n=qut.size();
        vector<int>g[n+1];
        vector<int>ind(n,0);
        vector<int>res(n,0);
        for(int i=0;i<n;i++){res[i]=i;}
        for(vector<int>&e:graph){
            int u=e[0],v=e[1];
            g[u].push_back(v);
            ind[v]+=1;
        }
        queue<int>q;for(int i=0;i<n;i++){if(ind[i]==0){q.push(i);}}
        while(q.size()){
            int u=q.front();q.pop();
            for(int v:g[u]){
                ind[v]-=1;if(ind[v]==0){q.push(v);}
                int un=res[u],vn=res[v];
                if(qut[un]<qut[vn]){
                    res[v]=un;
                }
            }
        }
        return res;
    }
};