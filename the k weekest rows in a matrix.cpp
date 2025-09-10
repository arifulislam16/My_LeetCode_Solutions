class Node{
    int sol,idx;

    Node(int sol,int idx){
        this.sol=sol;
        this.idx=idx;
    }
}
class Helper implements Comparator<Node>{
    public int compare(Node a,Node b){
        if(a.sol==b.sol){
            if(a.idx>b.idx){return 1;}
            return -1;
        }
        else{
            if(a.sol>b.sol){return 1;}
            return -1;
        }
    }
}
class Solution {
    int getsol(int mat[][],int currow,int col){
            int b=0,e=col-1;
            while(b<=e){
                int mid=b+(e-b)/2;
                if(mat[currow][mid]>=1){b=mid+1;}
                else{e=mid-1;}
            }
            return b;
    }
    public int[] kWeakestRows(int[][] mat, int k) {
        int row=mat.length,col=mat[0].length;
        int res[]=new int[k];
        
        ArrayList<Node>arr=new ArrayList<Node>();
        for(int i=0;i<row;i++){
            int sol=getsol(mat,i,col);
            Node nd=new Node(sol,i);
            arr.add(nd);

        }
       Collections.sort(arr,new Helper());
      
       for(int i=0;i<k;i++){
           res[i]=arr.get(i).idx;
       }
        return res;
        
    }
}