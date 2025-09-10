class Solution {
public:
  char ch[5]={'a','e','i','o','u'};
  int dp[51][9];
  int cnt(int i,int j,int n){
     if(i==n){return 1;}
     else if(dp[i][j]!=-1){return dp[i][j];}
     int ans=0;
     for(int k=j;k<5;k++){
         ans+=cnt(i+1,k,n);
     }
     return dp[i][j]=ans;
      
  }
    int countVowelStrings(int n) {
        memset(dp,-1,sizeof(dp));
        return cnt(0,0,n);
    }
};