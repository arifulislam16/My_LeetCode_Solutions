class Solution {
public:

    int n,m;
    int dx[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    bool inside(int i,int j,int n,int m){
        return i>=0&&i<n&&j>=0&&j<m;
    }
    bool visit1[502][502]={{false}},visit2[502][502]={{false}};
    void dfs(int i,int j,vector<vector<int>>&mat){
        visit1[i][j]=true;
        for(int k=0;k<4;k++){
            int x=i+dx[k][0],y=j+dx[k][1];
            if(inside(x,y,n,m)&&!visit1[x][y]&&mat[x][y]){
                dfs(x,y,mat);
            }
        }
    }
    void dfs(int i,int j,vector<vector<int>>&mat,bool &ok){
        visit2[i][j]=true;
        if(!visit1[i][j]){ok=false;}
        for(int k=0;k<4;k++){
            int x=i+dx[k][0],y=j+dx[k][1];
            if(inside(x,y,n,m)&&!visit2[x][y]&&mat[x][y]){dfs(x,y,mat,ok);}
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
       n=grid1.size();m=grid1[0].size();
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(grid1[i][j]&&!visit1[i][j]){
                   dfs(i,j,grid1);
               }
           }
       }
       int ans=0;
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(grid2[i][j]&&!visit2[i][j]){
                   bool ok=true;
                   dfs(i,j,grid2,ok);
                   if(ok){ans+=1;}
               }
           }
       }
       return ans;
    }
};