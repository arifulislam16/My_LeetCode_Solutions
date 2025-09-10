class Solution {
    int row,col;
    boolean visit[][]=new boolean[201][201];
    class Node{
        int x,y,d;
        Node(int x,int y){
            this.x=x;
            this.y=y;
        }
        Node(int x,int y,int d){
            this.x=x;
            this.y=y;
            this.d=d;
        }
    }
    ArrayList<Node>arr=new ArrayList<Node>();
    boolean inside(int x,int y,int row,int col){
        return x>=0&&x<row&&y>=0&&y<col;
    }
    int dx[][]={{1,0},{0,1},{-1,0},{0,-1}};

    void dfs(int i,int j,int mat[][]){
        visit[i][j]=true;
        mat[i][j]=2;
        arr.add(new Node(i,j));
        for(int k=0;k<4;k++){
            int x=i+dx[k][0],y=j+dx[k][1];
            if(inside(x,y,row,col)&&mat[x][y]==1&&!visit[x][y]){
                dfs(x,y,mat);
            }
        }
    }
    public int shortestBridge(int[][] grid) {
         row=grid.length;
         col=grid[0].length;
        int x=-1,y=-1;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){x=i;y=j;break;}
            }
            if(x!=-1&&y!=-1){break;}
        }
        dfs(x,y,grid);

       Queue<Node>q=new LinkedList<Node>();
       for(Node n:arr){
           q.add(new Node(n.x,n.y,0));
       }
       while(q.size()>0){
           int sz=q.size();
           while(sz-->0){
               Node cur=q.poll();
               if(grid[cur.x][cur.y]==1){return cur.d-1;}
               for(int k=0;k<4;k++){
                    x=cur.x+dx[k][0];
                    y=cur.y+dx[k][1];
                   if(inside(x,y,row,col)&&grid[x][y]!=2&&!visit[x][y]){
                       q.add(new Node(x,y,cur.d+1));
                       visit[x][y]=true;
                   }
               }
           }
       }
       return 0;
    }
}