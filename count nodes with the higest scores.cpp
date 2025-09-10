class Solution {
public:
  struct{
    int left,right;
    int lcnt,rcnt;
  }node[100001];
  long long maximum(long long a,long long b){
      if(a>b){return a;}
      return b;
  }
    int dfs(int u){
        if(u==-1){return 0;}
        int lcnt=dfs(node[u].left);
        int rcnt=dfs(node[u].right);
        node[u].lcnt=lcnt;
        node[u].rcnt=rcnt;
        return lcnt+rcnt+1;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        for(int i=0;i<n;i++){node[i].left=node[i].right=-1;node[i].lcnt=node[i].rcnt=0;}
        for(int i=0;i<n;i++){
            int u=parents[i],v=i;
            if(u==-1){continue;}
            if(node[u].left==-1){node[u].left=v;}
            else{node[u].right=v;}
        }

        dfs(0);
        unordered_map<long long ,long long >mp;
        long long mx=0;

        for(int i=0;i<n;i++){
            long long  lcnt=node[i].lcnt,rcnt=node[i].rcnt;
            long long  p=n-(lcnt+rcnt+1);
            if(lcnt==0){lcnt=1;}
            if(rcnt==0){rcnt=1;}
            if(p==0){p=1;}
            mx=maximum(mx,lcnt*rcnt*p);
            mp[lcnt*rcnt*p]++;
        }
        return mp[mx];
    }
};