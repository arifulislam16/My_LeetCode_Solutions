class Solution {
    int max(int a,int b){
        if(a>b){return a;}
        return b;
    }
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        ArrayList<ArrayList<Integer>>g=new ArrayList<ArrayList<Integer>>();
        for(int i=0;i<=n;i++){g.add(new ArrayList<Integer>());}
        int sor=0;
        for(int i=0;i<manager.length;i++){
            int u=manager[i],v=i;
            if(u==-1){sor=i;continue;}
            g.get(u).add(v);
        }
        Queue<int[]>q=new LinkedList<int[]>();
        q.add(new int[]{sor,0});
        int res=0;
        while(q.size()>0){
            int sz=q.size();
            while(sz-->0){
                int tmp[]=q.poll();
                int cid=tmp[0],cost=tmp[1];
                res=max(res,cost);
                for(int v:g.get(cid)){
                    int ncost=cost+informTime[cid];
                        q.add(new int[]{v,ncost});
                }
            }
        }
        return res;
      //  return 0;
    }
}