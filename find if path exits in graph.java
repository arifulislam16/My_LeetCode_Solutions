class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        ArrayList<ArrayList<Integer>>g=new ArrayList<ArrayList<Integer>>();
        for(int i=0;i<=n;i++){
            g.add(new ArrayList<Integer>());
        }
        int sz=edges.length;
       for(int i=0;i<sz;i++){
           int u=edges[i][0],v=edges[i][1];
           g.get(u).add(v);
           g.get(v).add(u);
       }
       Queue<Integer>q=new LinkedList<Integer>();
       
       q.add(source);
       boolean visit[]=new boolean[n+1];
       visit[source]=true;
       while(q.size()>0){
           int cur=q.peek();q.remove(q.peek());
           if(cur==destination){return true;}
           for(int nxt:g.get(cur)){
               if(visit[nxt]==true){continue;}
               q.add(nxt);
               visit[nxt]=true;
           }
       }
       return false;
    }
}