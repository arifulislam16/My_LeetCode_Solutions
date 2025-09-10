class Solution {
public:
int dp[50001];
int dfs(int i,vector<int>& arr){
    if(!arr[i]){return dp[i]=1;}
    if(dp[i]!=-1){return dp[i];}
    dp[i]=0;
    if(i+arr[i]<arr.size()){dp[i]|=dfs(i+arr[i],arr);}
    if(i-arr[i]>=0){dp[i]|=dfs(i-arr[i],arr);}
    return dp[i];
}
    bool canReach(vector<int>& arr, int start) {
        memset(dp,-1,sizeof(dp));
        return dfs(start,arr);
    }
};