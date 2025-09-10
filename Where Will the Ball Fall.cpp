class Solution {
public:
int cnt(int crow,int ccol,int row,int col,vector<vector<int>>&grid,
vector<vector<int>>&dp){
    if(crow==row){return ccol;}
    else if(dp[crow][ccol]!=-1){return dp[crow][ccol];}
    if(grid[crow][ccol]==1){
        if(ccol+1<col&&grid[crow][ccol+1]==1){
            return dp[crow][ccol]=cnt(crow+1,ccol+1,row,col,grid,dp);
        }
        return dp[crow][ccol]=-1;
    }
    else{
        if(ccol-1>=0&&grid[crow][ccol-1]==-1){
            return dp[crow][ccol]=cnt(crow+1,ccol-1,row,col,grid,dp);
        }
        return dp[crow][ccol]=-1;
    }
}
    vector<int> findBall(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        vector<int>res(col,0);
        vector<vector<int>>dp(row,vector<int>(col,-1));
        for(int i=0;i<col;i++){
            res[i]=cnt(0,i,row,col,grid,dp); 
        }
        return res;
    }
};