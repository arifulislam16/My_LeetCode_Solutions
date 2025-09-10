class Solution {
    public static boolean inside(int i,int j,int row,int col){
        return i>=0&&i<row&&j>=0&&j<col;
    }
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int row=image.length;
        int col=image[0].length;
        
        boolean visit[][]=new boolean[row][col];
        int c=image[sr][sc];
        int dx[][]={{1,0},{0,1},{-1,0},{0,-1}};
       
        Queue<int[]>q=new LinkedList<int[]>();
        q.add(new int[]{sr,sc});
        visit[sr][sc]=true;
        while(q.size()>0){
            int sz=q.size();
            while(sz>0){
                int cur[]=q.poll();
             
                int x=cur[0],y=cur[1];
                image[x][y]=color;
                for(int k=0;k<4;k++){
                    int tx=x+dx[k][0],ty=y+dx[k][1];
                    if(inside(tx,ty,row,col)&&!visit[tx][ty]&&image[tx][ty]==c){
                        q.add(new int[]{tx,ty});
                        visit[tx][ty]=true;
                    }
                }
                sz--;
            }
        }
        return image;
    }
}