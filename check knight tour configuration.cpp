class Solution {
    int row,col,mx=0,cnt=0;
    int max(int a,int b){
        if(a>b){return a;}
        return b;
    }
    boolean visit[][]=new boolean[201][201];
    HashMap<Integer,Integer[]>hm=new HashMap<Integer,Integer[]>();
    

    boolean inside(int x,int y){
        if(x>=0&&x<row&&y>=0&&y<col){return true;}
        return false;
    }

    int dx[][]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{-1,-2},{1,-2}};

    boolean isvalid(int x,int y,int i,int j){
        for(int k=0;k<8;k++){
            int tx=i+dx[k][0];
            int ty=j+dx[k][1];
            if(inside(tx,ty)&&!visit[tx][ty]&&(tx==x&&ty==y)){
                return true;
            }
        }
        return false;
    }

    boolean dfs(Integer i,Integer j){
        visit[i][j]=true;
      // System.out.print("now at (i,j,cnt)"+"("+i+","+j+","+cnt+")"+"\n");
        if(cnt==mx){return true;}
        cnt+=1;
        if(hm.containsKey(cnt)==false){
            System.out.print("nxt cnt is not possible\n");
            return false;}
        Integer st[]=hm.get(cnt);
        Integer x=st[0],y=st[1];
        if(!isvalid(x,y,i,j)){
           
            return false;}
        return dfs(x,y);
    }

    public boolean checkValidGrid(int[][] grid) {
        row=grid.length;
        col=grid[0].length;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                hm.put(grid[i][j],new Integer[]{i,j});
                mx=max(mx,grid[i][j]);
                visit[i][j]=false;
            }
        }
        Integer st[]=hm.get(0);
        if(st[0]!=0&&st[1]!=0){return false;}
        return dfs(0,0);
        
    }
}