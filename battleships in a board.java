class Solution {
    boolean inside(int i,int j,int row,int col){
        return i>=0&&i<row&&j>=0&&j<col;
    }
    void dfs(int i,int j,int row,int col,char mat[][],boolean visit[][]){
        visit[i][j]=true;
        if(inside(i+1,j,row,col)&&mat[i+1][j]=='X'&&!visit[i+1][j]){
            dfs(i+1,j,row,col,mat,visit);
        }
        if(inside(i,j+1,row,col)&&mat[i][j+1]=='X'&&!visit[i][j+1]){
            dfs(i,j+1,row,col,mat,visit);
        }
    }
    public int countBattleships(char[][] board) {
        int row=board.length;
        int col=board[0].length;
        boolean visit[][]=new boolean[row][col];
        int cnt=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='X'&&!visit[i][j]){
                    cnt+=1;
                    dfs(i,j,row,col,board,visit);
                }
            }
        }
        return cnt;
    }
}