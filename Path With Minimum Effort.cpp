class Solution {
    vector<vector<int>> dirs = {
                {-1,0},
        {0,-1},         {0,1},
                {1, 0}
    };
    int dx[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    bool inside(int i,int j,int row,int col){
        return i>=0&&i<row&&j>=0&&j<col;
    }
    bool ok(vector<vector<int>>&mat, int mx) {
       int row=mat.size(),col=mat[0].size();
       queue<pair<int,int>>q;
        vector<vector<bool>>visit(row+1,vector<bool>(col+1,false));
        visit[0][0]=false;
        q.push({0,0});
        while(q.size()){
            int sz=q.size();
            while(sz--){
                pair<int,int>p=q.front();q.pop();
                int i=p.first,j=p.second;
                if(i==row-1&&j==col-1){return true;}
                for(int k=0;k<4;k++){
                    int x=i+dx[k][0],y=j+dx[k][1];
                    if(inside(x,y,row,col)&&!visit[x][y]&&abs(mat[x][y]-mat[i][j])<=mx){
                        q.push({x,y});
                        visit[x][y]=true;
                    }
                }
            }
        }
        return false;
    }
    
public:
    int minimumEffortPath(vector<vector<int>>& mat) {
        int row=mat.size(),col=mat[0].size();
       int grid[row+1][col+1];
       for(int i=0;i<=row;i++){for(int j=0;j<=col;j++){grid[i][j]=1e9;}}
        grid[0][0]=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0,0});
        while(pq.size()){
            vector<int>tmp=pq.top();pq.pop();
            int d=tmp[0],i=tmp[1],j=tmp[2];
            if(i==row-1&&j==col-1){return d;}
            for(int k=0;k<4;k++){
                int x=i+dx[k][0],y=j+dx[k][1];
                if(inside(x,y,row,col)){
                    int nval=max(d,abs(mat[x][y]-mat[i][j]));
                    if(grid[x][y]>nval){
                        grid[x][y]=nval;
                        pq.push({nval,x,y});
                    }
                }
            }
        }
    return 1e9;
    }
};