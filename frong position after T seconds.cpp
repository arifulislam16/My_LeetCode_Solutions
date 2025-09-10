class Solution {
public:
struct cell{
    int node;
    int tm;
    double prob;
};
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
            vector<double>prob(n+1,0.0);
            vector<int>g[n+1];
            for(vector<int>e:edges){
                int u=e[0],v=e[1];
                g[u].push_back(v);
                g[v].push_back(u);
            }
            queue<int>q;
            vector<bool>visit(n+1,false);
            visit[1]=true;
            q.push(1);
            prob[1]=1.0;
            while(q.size()&&t-->0){
                int sz=q.size();
                while(sz-->0){
                    int curnode=q.front();q.pop();
                    int cnt=0;
                    for(int v:g[curnode]){if(!visit[v]){cnt+=1;}}
                    for(int v:g[curnode]){
                        if(!visit[v]){
                            prob[v]=prob[curnode]*(1.0/cnt);
                            q.push(v);
                            visit[v]=true;
                        }
                    }
                    if(cnt>0){prob[curnode]=0;}
                }
            }
            return prob[target];
    }
};