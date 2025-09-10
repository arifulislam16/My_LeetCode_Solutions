class Solution {
public:
int dp[501][501][2];
int cnt(int b,int e,int t,vector<int>&arr){
    if(b>e){return 0;}
    else if(b==e){return arr[b];}
    else if(dp[b][e][t]!=-1){return dp[b][e][t];}
    // b,e   b+1, e     
    //       b, e-1 
    if(t==0){
        int op1=cnt(b+1,e,1-t,arr)+arr[b];
        int op2=cnt(b,e-1,1-t,arr)+arr[e];
        return dp[b][e][t]=max(op1,op2);
    }
    else{
        int op1=cnt(b+1,e,1-t,arr);
        int op2=cnt(b,e-1,1-t,arr);
        return dp[b][e][t]=min(op1,op2);
    }
}
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        //return cnt(0,piles.size()-1,0,piles)>0;
        int totalsum=0;
        for(int x:piles){totalsum+=x;}
        int sum=cnt(0,piles.size()-1,0,piles);
        return totalsum-sum>0;
    }
};