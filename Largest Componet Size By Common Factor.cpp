class Solution {
public:
int getpar(int a,int par[]){
    int tmp=a;
    while(par[tmp]!=tmp){
        tmp=par[par[tmp]];
    }
    return tmp;
}
void getunion(int a,int b,int par[],int size[]){
    int pa=getpar(a,par);
    int pb=getpar(b,par);
    if(pa!=pb){
        if(size[pa]>size[pb]){
            size[pa]+=size[pb];
            par[pb]=pa;
        }
        else{
            size[pb]+=size[pa];
            par[pa]=pb;
        }
    }
    return ;
}
    int largestComponentSize(vector<int>& nums) {
        int n=nums.size();
        int par[100001];
        int size[100001];
        for(int i=0;i<=100000;i++){
            par[i]=i;
            size[i]=1;
        }
        for(int x:nums){
            for(int j=2;j*j<=x;j++){
                if(x%j==0){
                    // 6 2  = 3 
                    getunion(x,j,par,size);
                    getunion(x,x/j,par,size);
                }
            }
        }
        unordered_map<int,int>mp;
        int ans=0;
        for(int x:nums){
            int pa=getpar(x,par);
            mp[pa]+=1;
            ans=max(ans,mp[pa]);
        }
        return ans;
    }
};