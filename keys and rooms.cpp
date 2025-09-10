class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        queue<int>q;
        vector<int>g[n+1];
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[i].size();j++){
                int u=i,v=rooms[i][j];
                g[u].emplace_back(v);
                
            }
        }
        bool visit[n+1];memset(visit,false,sizeof(visit));
        visit[0]=true;
        q.push(0);
        unordered_map<int,int>mp;
        while(q.size()){
            int sz=q.size();
            while(sz-->0){
                int cur=q.front();q.pop();
                 for(int v:g[cur]){
                     if(!visit[v]){
                         q.push(v);
                         visit[v]=true;
                     }
                 }
            }
        }
        for(int i=0;i<n;i++){if(!visit[i]){return false;}}
        return true;
    }
};