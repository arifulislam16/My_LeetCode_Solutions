class Solution {
boolean ok(int i,int j,int row,int col,int grid[][]){
    for(int x=0;x<row;x++){
        if(x!=i&&grid[x][j]==1){return true;}
    }
    for(int y=0;y<col;y++){
        if(y!=j&&grid[i][y]==1){return true;}
    }
    return false;
}
    public int countServers(int[][] grid) {
    int res=0;
        int row=grid.length;
        int col=grid[0].length;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    if(ok(i,j,row,col,grid)){res++;}
                }
            }
        }
        return res;
    }
}