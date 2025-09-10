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
    if(size[a]>size[b]){
        par[b]=a;
        size[a]+=size[b];
    }
    else{
        par[a]=b;
        size[b]+=size[a];
    }
    return ;
}
    int minScore(int n, vector<vector<int>>& roads) {
        int par[n+1],size[n+1];
        for(int i=0;i<=n;i++){par[i]=i;size[i]=1;}
        for(vector<int>e:roads){
            int u=e[0],v=e[1];
            int pa=getpar(u,par),pb=getpar(v,par);
            if(pa!=pb){getunion(pa,pb,par,size);}
        }
        int ans=1e9;
        for(vector<int>e:roads){
            int u=e[0],wt=e[2];
            int pa=getpar(u,par),pb=getpar(1,par);
            if(pa==pb){ans=min(ans,wt);}
        }
        return ans;
    }
};