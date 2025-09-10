class Solution {
public:
bool visit[301][301];
int dx[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool inside(int i,int j,int row,int col){
    return i>=0&&i<row&&j>=0&&j<col;
}
void dfs(int i,int j,int row,int col,
vector<vector<char>>&mat){
    visit[i][j]=true;
    for(int k=0;k<4;k++){
        int x=i+dx[k][0],
        y=j+dx[k][1];
        if(inside(x,y,row,col)&&
        visit[x][y]==false&&mat[x][y]=='1'){
            dfs(x,y,row,col,mat);
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        memset(visit,false,sizeof(visit));
        int row=grid.size();
        int col=grid[0].size();
        int ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!visit[i][j]&&grid[i][j]=='1'){
                    ans+=1;
                    dfs(i,j,row,col,grid);
                }
            }
        }
        return ans;
    }
};