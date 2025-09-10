class Solution {
public:
int dp[101][10001];
int cnt(int i,int j,string&s,string&t){
    if(i>=s.size()){
        return true;
    }
    if(j>=t.size()){return false;}
    if(dp[i][j]!=-1){return dp[i][j];}
    if(s[i]==t[j]){
        return  dp[i][j]=cnt(i+1,j+1,s,t);
    }
    else{
        return dp[i][j]=cnt(i,j+1,s,t);
    }
}
    bool isSubsequence(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return cnt(0,0,s,t);
    }
};