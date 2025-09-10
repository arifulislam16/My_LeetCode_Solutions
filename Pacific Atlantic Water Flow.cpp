class Solution {
public:
 bool inside(int i,int j,int row,int col){
     return i>=0&&i<row&&j>=0&&j<col;
 }
 int dx[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
       int row=mat.size(),col=mat[0].size();
       bool pac[row][col],oce[row][col];
       for(int i=0;i<row;i++){
           for(int j=0;j<col;j++){
               pac[i][j]=oce[i][j]=false;
           }
       }
       bool visit[row][col];
       memset(visit,false,sizeof(visit));
       queue<pair<int,int>>q;
       for(int i=0;i<col;i++){q.push({0,i});}
       for(int i=1;i<row;i++){q.push({i,0});}
       while(q.size()){
           int sz=q.size();
           while(sz--){
               pair<int,int>p=q.front();q.pop();
               int i=p.first,j=p.second;
               if(visit[i][j]){continue;}
               visit[i][j]=true;
               pac[i][j]=true;
               for(int k=0;k<4;k++){
                   int x=i+dx[k][0],y=j+dx[k][1];
                if(inside(x,y,row,col)&&
                mat[x][y]>=mat[i][j]){q.push({x,y});}
               }
               
           }
       }
       
       memset(visit,false,sizeof(visit));
        for(int i=0;i<col;i++)     {q.push({row-1,i});}
        for(int i=0;i<row;i++){q.push({i,col-1});}
        while(q.size()){
            int sz=q.size();
            while(sz--){
                pair<int,int>p=q.front();
                q.pop();
                int i=p.first,j=p.second;
                if(visit[i][j]){continue;}
                visit[i][j]=true;
                oce[i][j]=true;
                for(int k=0;k<4;k++){
                    int x=i+dx[k][0],y=j+dx[k][1];
                    if(inside(x,y,row,col)&&mat[x][y]>=mat[i][j]){
                        q.push({x,y});
                    }

                }
            }
        }
        vector<vector<int>>res;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(pac[i][j]&&oce[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};