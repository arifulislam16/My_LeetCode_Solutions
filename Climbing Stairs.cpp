class Solution {
public:
int dp[100];
int cnt(int i,int n){
    if(i==n){return 1;}
    else if(i>n){return 0;}
    if(dp[i]!=-1){return dp[i];}
    int op1=cnt(i+1,n);
    int op2=cnt(i+2,n);
    return dp[i]=op1+op2;
}
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return cnt(0,n);
    }
};