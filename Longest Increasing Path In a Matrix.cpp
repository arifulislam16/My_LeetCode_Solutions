class Solution {
public:
bool visit[201][201];
int dp[201][201];
int ans=1;
bool inside(int i,int j,int row,int col){
    return i>=0&&i<row&&j>=0&&j<col;
}
int dx[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
 int dfs(int i,int j,int row,int col,vector<vector<int>>&mat){
     if(dp[i][j]!=-1){return dp[i][j];}
     dp[i][j]=1;
     for(int k=0;k<4;k++){
         int x=i+dx[k][0],y=j+dx[k][1];
         if(inside(x,y,row,col)&&mat[i][j]<mat[x][y]){
             dp[i][j]=max(dp[i][j],dfs(x,y,row,col,mat)+1);
         }
     }
     return dp[i][j];
 }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof(dp));
        int row=matrix.size();
        int col=matrix[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                ans=max(ans,dfs(i,j,row,col,matrix));
            }
        }
        return ans;
    }
};