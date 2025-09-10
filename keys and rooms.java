class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        ArrayList<ArrayList<Integer>>g=new ArrayList<ArrayList<Integer>>();
        int n=rooms.size();
        for(int i=0;i<=n;i++){
            g.add(new ArrayList<Integer>());
        }
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms.get(i).size();j++){
                int u=i,v=rooms.get(i).get(j);
                g.get(u).add(v);
            }
        }
    boolean visit[]=new boolean[n+1];
     visit[0]=true;
     Queue<Integer>q=new LinkedList<Integer>();
     q.add(0);
     while(q.size()>0){
         int sz=q.size();
         while(sz-->0){
             int cur=q.peek();q.remove(q.peek());
             for(int v:g.get(cur)){
                 if(visit[v]==false){
                     q.add(v);
                     visit[v]=true;
                 }
             }
         }
     }
     for(int i=0;i<n;i++){
         if(visit[i]==false){return false;}
     }
     return true;

    
    }
}