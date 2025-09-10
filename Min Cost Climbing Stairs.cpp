class Solution {
public:
 int dp[1001];
 int cnt(int i,vector<int>&cost,int n){
     if(i>=n){return 0;}
     else if(dp[i]!=-1){return dp[i];}
     int r1=cnt(i+1,cost,n);
     int r2=cnt(i+2,cost,n);
     return dp[i]=min(r1,r2)+cost[i];
 }
    int minCostClimbingStairs(vector<int>& cost) {
       memset(dp,-1,sizeof(dp));
       int n=cost.size();
       return min(cnt(0,cost,n),cnt(1,cost,n));
    }
};