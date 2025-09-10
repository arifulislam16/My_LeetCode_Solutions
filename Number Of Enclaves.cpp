class Solution {
public:
bool inside(int i,int j,int n,int m){
    return i>=0&&i<n&&j>=0&&j<m;
}
int dx[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool isboundary(int i,int j,int n,int m){
    if(i==0||i==n-1||j==0||j==m-1){return true;}
    return false;
}
void dfs(int i,int j,int n,int m,vector<vector<bool>>&visit,vector<vector<int>>&mat,int &tmp,
bool &ok){
    visit[i][j]=true;
    tmp+=1;
    if(isboundary(i,j,n,m)){ok=false;}
    for(int k=0;k<4;k++){
        int x=i+dx[k][0];
        int y=j+dx[k][1];
        if(inside(x,y,n,m)&&!visit[x][y]&&mat[x][y]){
            dfs(x,y,n,m,visit,mat,tmp,ok);
        }
    }
    return ;
}
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int res=0;
        vector<vector<bool>>visit(n+1,vector<bool>(m+1,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]&&!visit[i][j]){
                    int tmp=0;bool ok=true;
                    dfs(i,j,n,m,visit,grid,tmp,ok);
                    if(ok){res+=tmp;}
                }
            }
        }
        return res;
    }
};