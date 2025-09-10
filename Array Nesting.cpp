class Solution {
public:
void dfs(int idx,vector<int>&v,
bool visit[],int&tmp){
    visit[idx]=true;
    tmp+=1;
    int nxt=v[idx];
    if(!visit[nxt]){
        dfs(nxt,v,visit,tmp);
    }
    return ;
}
    int arrayNesting(vector<int>& nums) {
        bool visit[nums.size()+1];
        memset(visit,false,sizeof(visit));
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(!visit[i]){
                int tmp=0;
                dfs(i,nums,visit,tmp);
                ans=max(tmp,ans);
            }
        }
        return ans;
    }
};