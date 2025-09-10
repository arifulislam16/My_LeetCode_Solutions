class Solution {
public:
int getpar(int a,int par[]){
    int tmp=a;
    while(par[tmp]!=tmp){
        tmp=par[par[tmp]];
    }
    return tmp;
}

void getunion(int pa,int pb,int par[],
int size[]){
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
    int makeConnected(int n, vector<vector<int>>& con) {
           int par[n+1],size[n+1];
           bool visit[n+1];
    for(int i=0;i<n;i++){
        par[i]=i;
        size[i]=1;
        visit[i]=false;
    }
    int ex=0;
    for(vector<int>e:con){
        int u=e[0],v=e[1];
        int pa=getpar(u,par);
        int pb=getpar(v,par);
        if(pa!=pb){
            getunion(pa,pb,par,size);
        }
        else{ex+=1;}
    }
    int g=0;
    for(int i=0;i<n;i++){
        int pa=getpar(i,par);
        if(!visit[pa]){
            visit[pa]=true;
            g+=1;
        }
    }
    int need=g-1;
    if(ex<need){return -1;}
    else{return need;}
    }
};