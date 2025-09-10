class Solution {
public:
bool inside(int i,int j,int n,int m){
    return i>=0&&i<n&&j>=0&&j<m;
}
int dx[4][2]={{1,0,},{0,1},{0,-1},{-1,0}};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int qz=queries.size();
        pair<int,int>p[queries.size()];
        for(int i=0;i<queries.size();i++){
            p[i]={queries[i],i};
        }
        sort(p,p+qz);
        vector<int>cnt(qz,0);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visit(n+1,vector<bool>(m+1,false));
        visit[0][0]=true;
        pq.push({grid[0][0],0,0});
        int count=0;
        for(pair<int,int>i:p){
            int val=i.first;
            int idx=i.second;
            while(pq.size()){
                vector<int>tmp=pq.top();
                int gval=tmp[0],tx=tmp[1],ty=tmp[2];
                if(gval>=val){break;}
                count+=1;
                pq.pop();
                for(int k=0;k<4;k++)              {
                    int x=tx+dx[k][0];
                    int y=ty+dx[k][1];
                    if(inside(x,y,n,m)&&!visit[x][y]){
                        pq.push({grid[x][y],x,y});
                        visit[x][y]=true;
                    }
                }
            }
            cnt[idx]=count;
        }
        return cnt;
    }
};