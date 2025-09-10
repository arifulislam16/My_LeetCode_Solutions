class Solution {
public:
int row,col;
 bool visit[101][101];
bool inside(int i,int j){
    return i>=0&&i<row&&j>=0&&j<col;
}
int dx[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool isboundar(int i,int j){
    if(i==0||i==row-1||j==0||j==col-1){
        return true;
    }
    return false;
}
void dfs(int i,int j,
vector<vector<int>>&mat,bool &ok){
    visit[i][j]=true;
    if(isboundar(i,j)){ok=false;}
    for(int k=0;k<4;k++){
        int x=i+dx[k][0];
        int y=j+dx[k][1];
        if(inside(x,y)&&!visit[x][y]&&
        mat[x][y]==0){
            dfs(x,y,mat,ok);
        }
    }
    return ;
}
    int closedIsland(vector<vector<int>>& grid) {
        row=grid.size();
        col=grid[0].size();
        int ans=0;
        memset(visit,false,sizeof(visit));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]){continue;}
            if(!visit[i][j]){
    bool ok=true;
    dfs(i,j,grid,ok);
    if(ok){ans+=1;}
            }
        }
    }
    return ans;
    }
};