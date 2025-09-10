class Solution {
public:
bool inside(int i,int j,int n,int m){
    return i>=0&&i<n&&j>=0&&j<m;
}
int dx[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<bool>>visit(n+1,vector<bool>(m+1,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]&&!visit[i][j]){
                    queue<pair<int,int>>q;
                    int tmp=0;
                    q.push({i,j});
                    visit[i][j]=true;
                    while(q.size()){
                        int sz=q.size();
                        while(sz--){
                            pair<int,int>p=q.front();q.pop();
                            tmp+=1;
                            int i=p.first,j=p.second;
                           
                            for(int k=0;k<4;k++){
                                int x=i+dx[k][0],y=j+dx[k][1];
                                if(inside(x,y,n,m)&&!visit[x][y]&&grid[x][y]){
                                    q.push({x,y});
                                    visit[x][y]=true;
                                }
                            }
                        }
                    }
                    ans=max(ans,tmp);
                }
            }
        }
        return ans;
    }
};