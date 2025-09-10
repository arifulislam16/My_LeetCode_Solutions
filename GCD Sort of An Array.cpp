class Solution {
public:
int getpar(int a,int par[]){
    int tmp=a;
    while(par[tmp]!=tmp){
        tmp=par[par[tmp]];
    }
    return tmp;
}
void getunion(int a,int b,int par[],
int size[]){
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
    bool gcdSort(vector<int>& nums) {
      int par[100001],size[100001];
      for(int i=0;i<100001;i++)  {
          par[i]=i;
          size[i]=1;
      }
      for(int n:nums){
          for(int j=2;j*j<=n;j++){
              if(n%j==0){
                  getunion(n,j,par,size);
                  getunion(n,n/j,par,size);
              }
          }
      }
      bool ok=true;
    vector<int>v(nums.begin(),nums.end());
    sort(v.begin(),v.end());
    for(int i=0;i<nums.size();i++){
        int pa=getpar(nums[i],par);
        int pb=getpar(v[i],par);
        if(pa!=pb){return false;}
    }
    return true;
    }
};