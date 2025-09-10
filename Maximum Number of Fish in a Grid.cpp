class Solution {
   boolean visit[][]=new boolean[21][21];
   int dp[][]=new int[21][21];
boolean inside(int x,int y,int row,int col){
    return x>=0&&x<row&&y>=0&&y<col;
}

int dx[][]={{1,0},{0,1},{-1,0},{0,-1}};
int max(int a,int b){
    if(a>b){return a;}
    return b;
}
    int dfs(int i,int j,int row,int col,int mat[][]){
        if(dp[i][j]!=-1){return dp[i][j];}
        visit[i][j]=true;
        int res=mat[i][j];
        for(int k=0;k<4;k++){
            int x=i+dx[k][0];
            int y=j+dx[k][1];
            if(inside(x,y,row,col)&&mat[x][y]>0&&!visit[x][y]){
                res+=dfs(x,y,row,col,mat);
            }
        }
        return dp[i][j]=res;
    }
    public int findMaxFish(int[][] grid) {
        int row=grid.length;
        int col=grid[0].length;
        for(int i=0;i<21;i++){
            for(int j=0;j<21;j++){visit[i][j]=false;dp[i][j]=-1;}
        }
        int res=0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]>0&&!visit[i][j]){
                    res=max(res,dfs(i,j,row,col,grid));
                }
            }
        }
        return res;
    }
}