class Solution {
public:
void dfs(int u,unordered_map<int,int>&visit,unordered_map<int,vector<int>>&g,int&cnt){
    visit[u]=1;
    cnt+=1;
    for(int v:g[u]){
        if(visit[v]==0){
            dfs(v,visit,g,cnt);
        }
    }
    return;
}
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){mp.insert({nums[i],i+1});}
        int n=nums.size();
        unordered_map<int,vector<int>>g;
        for(auto &[i,val]:mp){

            if(mp.find(i-1)!=mp.end()){g[i].push_back(i-1);g[i-1].push_back(i);}
            if(mp.find(i+1)!=mp.end()){g[i].push_back(i+1);g[i+1].push_back(i);}
        }
        unordered_map<int,int>visit;
        int ans=0;
        for(int x:nums){
            if(visit[x]==0){
                int cnt=0;
                dfs(x,visit,g,cnt);
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};