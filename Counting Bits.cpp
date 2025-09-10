class Solution {
public:
 int dp[100001];
 int cnt(int i){
     if(i==0){return dp[i]=0;}
     if(i==1||i==2||i==4){return dp[i]=1;}
     else if(i==3||i==5){return dp[i]=2;}
     else if(dp[i]!=-1){return dp[i];}
     if(i&1){return dp[i]= cnt(i/2)+1;}
     else{return dp[i]=cnt(i/2);}
 }
    vector<int> countBits(int n) {
        memset(dp,-1,sizeof(dp));
        vector<int>ans(n+1,0);
        for(int i=0;i<=n;i++){
            ans[i]=cnt(i);
        }       
        return ans;
    }
};