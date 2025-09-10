class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        vector<vector<int>>mat(row,vector<int>(col,0));
        int rone[row],rzero[row],cone[col],czero[col];
  for(int i=0;i<row;i++){rone[i]=rzero[i]=0;}
  for(int i=0;i<col;i++){cone[i]=czero[i]=0;}
  for(int i=0;i<row;i++){
  	for(int j=0;j<col;j++){
  		if(grid[i][j]==1){rone[i]+=1;}
  		else{rzero[i]+=1;}
  	}
  }
  for(int i=0;i<col;i++){
  	for(int j=0;j<row;j++){
  		(grid[j][i]==1)?cone[i]+=1:czero[i]+=1;
  	}
  }
  //diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj
  vector<vector<int>>res(row,vector<int>(col,0));
  for(int i=0;i<row;i++){
  	for(int j=0;j<col;j++){
  		res[i][j]=rone[i]+cone[j]-rzero[i]-czero[j];
  	}
  }
  return res;
    }
};