class Solution {
public:
int getpar(int a,int par[]){
    int tmp=a;
    while(par[tmp]!=tmp){
        tmp=par[par[tmp]];
    }
    return tmp;
}
void getunion(int pa,int pb,int par[],int size[]){
    if(size[pa]>size[pb]){
        size[pa]+=size[pb];
        par[pb]=pa;
    }
    else{
        size[pb]+=size[pa];
        par[pa]=pb;
    }
    return ;
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int par[1001];
        int size[1001];
        for(int i=0;i<1001;i++){
            par[i]=i;
            size[i]=1;
        }
       for(vector<int>e:edges){
           int u=e[0],v=e[1];
           int pa=getpar(u,par);
           int pb=getpar(v,par);
           if(pa!=pb){
               getunion(pa,pb,par,size);
           }
           else{
               return {u,v};
           }
       }
    return {-1,-1};
    }
};