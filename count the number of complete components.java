class Solution {
    void dfs(int u,ArrayList<ArrayList<Integer>>arr,int visit[],
    ArrayList<Integer>res){
        visit[u]=1;
        res.add(u);
        for(int v:arr.get(u)){
            if(visit[v]==0){
                dfs(v,arr,visit,res);
            }
        }
        return;
    }
    public int countCompleteComponents(int n, int[][] edges) {
        int ind[]=new int[n+1];
        for(int i=0;i<=n;i++){ind[i]=0;}
        ArrayList<ArrayList<Integer>>arr=new ArrayList<ArrayList<Integer>>();
        for(int i=0;i<=n;i++){
            arr.add(new ArrayList<Integer>());
        }
        for(int e[]:edges){
            int u=e[0],v=e[1];
            arr.get(u).add(v);
            arr.get(v).add(u);
            ind[u]+=1;
            ind[v]+=1;
        }
        int visit[]=new int[n+1];
        int cnt=0;
        for(int i=0;i<n;i++){   
            if(visit[i]==0){
                ArrayList<Integer>res=new ArrayList<Integer>();
                dfs(i,arr,visit,res);
                int sz=res.size();
                boolean ok=true;
                for(int x:res){
                    if(ind[x]!=sz-1){ok=false;break;}
                }
                if(ok){cnt++;}
            }
        }
    return cnt;
    }
}