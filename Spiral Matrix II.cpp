class Solution {
public:
    bool visit[21][21]={{false}};
    int mat[21][21];
    int n;
    bool inside(int i,int j){
	return i>=0&&i<n&&j>=0&&j<n;
}
void cnt(int i,int j,int d,int n,int val){
	mat[i][j]=val;
	visit[i][j]=true;
	if(d==0){
		if(inside(i,j+1)&&!visit[i][j+1]){cnt(i,j+1,d,n,val+1);}
		else if(inside(i+1,j)&&!visit[i+1][j]){cnt(i+1,j,d+1,n,val+1);}
	}
	else if(d==1){
		if(inside(i+1,j)&&!visit[i+1][j]){cnt(i+1,j,d,n,val+1);}
		else if(inside(i,j-1)&&!visit[i][j-1]){cnt(i,j-1,d+1,n,val+1);}
	}
	else if(d==2){
		if(inside(i,j-1)&&!visit[i][j-1]){cnt(i,j-1,d,n,val+1);}
		else if(inside(i-1,j)&&!visit[i-1][j]){cnt(i-1,j,d+1,n,val+1);}
	}
	else if(d==3){
		if(inside(i-1,j)&&!visit[i-1][j]){cnt(i-1,j,d,n,val+1);}
		else if(inside(i,j+1)&&!visit[i][j+1]){cnt(i,j+1,0,n,val+1);}
	}
}
    vector<vector<int>> generateMatrix(int N) {
     vector<vector<int>>res;
     n=N;
      cnt(0,0,0,n,1);
      for(int i=0;i<N;i++){
          vector<int>r;
          for(int j=0;j<N;j++){r.emplace_back(mat[i][j]);}
          res.emplace_back(r);
      }
      return res;
    }
    
};