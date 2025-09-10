class Solution {
public:
int row,col;
bool inside(int i,int j){
    return i>=0&&i<row&&j>=0&&j<col;
}
int dx[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool dfs(int i,int j,int px,int py,vector<vector<char>>&grid,vector<vector<bool>>&visit){
    visit[i][j]=true;
    for(int k=0;k<4;k++){
        int x=i+dx[k][0],y=j+dx[k][1];
        if(inside(x,y)&&grid[x][y]==grid[i][j]){
            if(!visit[x][y]){
                if(dfs(x,y,i,j,grid,visit)){return true;}
            }
            else{
                if(!(x==px&&y==py)){return true;}
            }
        }  
    }
    return false;
}
    bool containsCycle(vector<vector<char>>& grid) {
        row=grid.size(),col=grid[0].size();
        vector<vector<bool>>visit(row+1,vector<bool>(col+1,false));
        /*
          vector<vector<bool>>v  =  { {1,2,3,4,5,6},  {1,2,3,4,5,6,7,8,9,10} ,{1,2,40},{1} } 
        */
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!visit[i][j]){
                    if(dfs(i,j,-1,-1,grid,visit)){return true;}
                }
            }
        }
        return false;
    }
};