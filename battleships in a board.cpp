class Solution {
public:
bool inside(int i,int j,int row,int col){
    return i>=0&&i<row&&j>=0&&j<col;
}
void dfs(int i,int j,int row,int col,vector<vector<char>>& mat,vector<vector<bool>>&visit){
    visit[i][j]=true;
    cout<<i<<','<<j<<"\n";
    if(inside(i,j+1,row,col)&&!visit[i][j+1]&&mat[i][j+1]=='X'){
        dfs(i,j+1,row,col,mat,visit);
    }
    if(inside(i+1,j,row,col)&&!visit[i+1][j]&&mat[i+1][j]=='X'){
        dfs(i+1,j,row,col,mat,visit);
    }
    return;
}
    int countBattleships(vector<vector<char>>& board) {
       int row=board.size();
       int col=board[0].size();
       vector<vector<bool>>visit(row,vector<bool>(col,false));
       int cnt=0;
       for(int i=0;i<row;i++){
           for(int j=0;j<col;j++){
               if(board[i][j]=='X'&&!visit[i][j]){
                   cnt+=1;
                   cout<<"start from: "<<i<<","<<j<<'\n';
                   dfs(i,j,row,col,board,visit);
               }
           }
       }
       return cnt;
    }
};