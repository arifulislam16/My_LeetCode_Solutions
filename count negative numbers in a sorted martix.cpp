class Solution {
public:
int getpos(vector<int>&v,int row,int col){
    int b=0,e=v.size()-1;
    while(b<=e){
        int mid=b+(e-b)/2;
        if(v[mid]>=0){b=mid+1;}
        else{e=mid-1;}
    }
    return b;
}
    int countNegatives(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int count=0;
        for(int i=0;i<row;i++){
            count+=col-getpos(grid[i],row,col);
        }
        return count;
    }
};