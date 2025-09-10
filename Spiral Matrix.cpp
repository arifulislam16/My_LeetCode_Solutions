class Solution {
public:
    #define eb empalce_back
    bool inside(int i,int j,int row,int col){
        return i>=0&&i<row&&j>=0&&j<col;
    }
    void cnt(int i,int j,int d,int row,int col,vector<vector<int>>&mat,vector<int>&res,vector<vector<bool>>&visit){
        res.emplace_back(mat[i][j]);
        visit[i][j]=true;
        if(d==0){
            if(inside(i,j+1,row,col)&&!visit[i][j+1]){cnt(i,j+1,d,row,col,mat,res,visit);}
            else if(inside(i+1,j,row,col)&&!visit[i+1][j]){cnt(i+1,j,d+1,row,col,mat,res,visit);}
        }
        else if(d==1){
            if(inside(i+1,j,row,col)&&!visit[i+1][j]){cnt(i+1,j,d,row,col,mat,res,visit);}
            else if(inside(i,j-1,row,col)&&!visit[i][j-1]){cnt(i,j-1,d+1,row,col,mat,res,visit);}
        }
        else if(d==2){
            if(inside(i,j-1,row,col)&&!visit[i][j-1]){cnt(i,j-1,d,row,col,mat,res,visit);}
            else if(inside(i-1,j,row,col)&&!visit[i-1][j]){cnt(i-1,j,d+1,row,col,mat,res,visit);}
        }
        else {
            if(inside(i-1,j,row,col)&&!visit[i-1][j]){
                cnt(i-1,j,d,row,col,mat,res,visit);
            }
            else if(inside(i,j+1,row,col)&&!visit[i][j+1]){
                cnt(i,j+1,0,row,col,mat,res,visit);
            }
        }

    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size(),col=matrix[0].size();
        vector<vector<bool>>visit(row+1,vector<bool>(col+1,false));
        vector<int>res;
        cnt(0,0,0,row,col,matrix,res,visit);
        return res;
    }
};