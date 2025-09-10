class Solution {
public:
bool visit[201][201];
int ans=0;
vector<pair<int,int>>res;
bool inside(int i,int j,int row,int col){
    return i>=0&&i<row&&j>=0&&j<col;
}
int dx[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int i,int j,int row,int col,
vector<vector<int>>&mat){
    visit[i][j]=true;
    res.push_back({i,j});
    int tmp=0;
    for(int k=0;k<4;k++){
        int x=i+dx[k][0],y=j+dx[k][1];
        if(inside(x,y,row,col)&&mat[x][y]==1&&!visit[x][y]){
            //tmp+=1;   
            dfs(x,y,row,col,mat);
        }
    }
    //ans+=4-tmp;
    return ;
}
    int islandPerimeter(vector<vector<int>>& grid) {
      int row=grid.size()  ;
      int col=grid[0].size();
      memset(visit,false,sizeof(visit));
      for(int i=0;i<row;i++){
          for(int j=0;j<col;j++){
              if(grid[i][j]==1){
                  dfs(i,j,row,col,grid);
                  goto here;
              }
          }
      }
      here:
      for(pair<int,int>p:res){
          int tmp=0;
          for(int k=0;k<4;k++){
              int x=p.first+dx[k][0];
              int y=p.second+dx[k][1];
              if(inside(x,y,row,col)&&grid[x][y]==1){
                  tmp+=1;
              }
          }
          ans+=4-tmp;
      }
      return ans;
  //    return ans;
        
    }
};