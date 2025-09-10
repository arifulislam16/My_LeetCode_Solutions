class Solution {
public:
int dp[100001][2];
int cnt(int i,int j,vector<int>&cost){
   if(i>=cost.size()){return 0;}
   else if(dp[i][j]!=-1){return dp[i][j];}
   if(j==0){
       int op1=cnt(i+1,1,cost)-cost[i];
       int op2=cnt(i+1,j,cost);
       return dp[i][j]=max(op1,op2);
   }
   else{
       int op1=cnt(i+1,j,cost);
       int op2=cost[i];
       return dp[i][j]=max(op1,op2);
   }
}
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return cnt(0,0,prices);
    }
};