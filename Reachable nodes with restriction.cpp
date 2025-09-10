class Solution {
    public int reachableNodes(int n, int[][] edges, int[] restricted) {
        ArrayList<ArrayList<Integer>>g=new ArrayList<ArrayList<Integer>>();
        for(int i=0;i<=n;i++){
            g.add(new ArrayList<Integer>());
        }
        for(int i=0;i<edges.length;i++){
            int u=edges[i][0],v=edges[i][1];
            g.get(u).add(v);
            g.get(v).add(u);
        }

        HashMap<Integer,Integer>hm=new HashMap<Integer,Integer>();
        for(int v:restricted){hm.put(v,1);}
        Queue<Integer>q=new LinkedList<Integer>();
        q.add(0);
        boolean visit[]=new boolean[100001];
        visit[0]=true;
        int res=0;
        while(q.size()>0){
            int sz=q.size();
            while(sz-->0){
                int cur=q.poll();
                res++;
                for(int v:g.get(cur)){
                    if(hm.containsKey(v)){continue;}
                    if(!visit[v]){q.add(v);visit[v]=true;}
                }
            }
        }
return res;
    }
}