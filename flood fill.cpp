class Solution {
public:
bool inside(int x,int y,int row,int col){
    return x>=0&&x<row&&y>=0&&y<col;
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row=image.size(),col=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vector<vector<bool>>visit(row,vector<bool>(col,false));
        visit[sr][sc]=true;
        int c=image[sr][sc];
        int dx[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        while(q.size()){
            int sz=q.size();
            while(sz--){
                pair p=q.front();q.pop();
                int x=p.first,y=p.second;
                image[x][y]=color;
                for(int k=0;k<4;k++){
                    int tx=x+dx[k][0],ty=y+dx[k][1];
                    if(inside(tx,ty,row,col)&&!visit[tx][ty]&&image[tx][ty]==c){
                        q.push({tx,ty});
                        visit[tx][ty]=true;
                    }
                }
            }
        }
        return image;
    }
};