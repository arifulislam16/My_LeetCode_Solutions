class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool>visit(n+1,false);
        vector<pair<int,int>>g[n+1];
        for(vector<int>e:meetings){
            int u=e[0],v=e[1],tm=e[2];
            g[u].push_back({v,tm});
            g[v].push_back({u,tm});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        pq.push({0,firstPerson});

        while(pq.size()){
            pair<int,int>cur=pq.top();pq.pop();
            int tm=cur.first,person=cur.second;
            if(visit[person]){continue;}
            visit[person]=true;
            for(pair<int,int>p:g[person]){
                int nperson=p.first,nxtm=p.second;
                if(!visit[nperson]&&tm<=nxtm){
                    pq.push({nxtm,nperson});
                    //visit[nperson]=true;
                }
            }
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            if(visit[i]){res.push_back(i);}
        }
        return res;
    }
};