class Solution {
public:
bool inside(int i,int j,int row,int col){
    return i>=0&&i<row&&j>=0&&j<col;
}
int dx[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    bool visit[201][201];
    void dfs(int i,int j,int row,int col,vector<vector<char>>&mat){
        visit[i][j]=true;
        for(int k=0;k<4;k++){
            int x=i+dx[k][0],y=j+dx[k][1];
            if(inside(x,y,row,col)&&!visit[x][y]&&mat[x][y]=='O'){
                dfs(x,y,row,col,mat);
            }
        }
    }
    void dfs_2(int i,int j,int row,int col,vector<vector<char>>&mat){
        visit[i][j]=true;
        mat[i][j]='X';
        for(int k=0;k<4;k++){
            int x=i+dx[k][0],y=j+dx[k][1];
            if(inside(x,y,row,col)&&!visit[x][y]&&mat[x][y]=='O'){
                dfs_2(x,y,row,col,mat);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int row=board.size(),col=board[0].size();
       memset(visit,false,sizeof(visit));
       for(int i=0;i<col;i++){
           if(board[0][i]=='O'){dfs(0,i,row,col,board);}
           if(board[row-1][i]=='O'){dfs(row-1,i,row,col,board);}
       }
       for(int i=0;i<row;i++){
           if(board[i][0]=='O'){dfs(i,0,row,col,board);}
           if(board[i][col-1]=='O'){dfs(i,col-1,row,col,board);}
       }
       for(int i=0;i<row;i++){
           for(int j=0;j<col;j++){
               if(board[i][j]=='O'&&!visit[i][j]){
                   dfs_2(i,j,row,col,board);
               }
           }
       }
       return ;
    }
};