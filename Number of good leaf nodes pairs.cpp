/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    HashMap<TreeNode,TreeNode>par=new HashMap<TreeNode,TreeNode>();
    HashMap<TreeNode,Integer>level=new HashMap<TreeNode,Integer>();
    ArrayList<TreeNode>arr=new ArrayList<TreeNode>();

    boolean isleaf(TreeNode root){
        if(root.left==null&&root.right==null){return true;}
        return false;
    }
    void dfs(TreeNode root, TreeNode p,int d){
        if(root==null){return;}
        par.put(root,p);
        level.put(root,d);
        if(isleaf(root)){arr.add(root);return;}
        if(root.left!=null){dfs(root.left,root,d+1);}
        if(root.right!=null){dfs(root.right,root,d+1);}
        return;
    }

    int getDis(TreeNode a ,TreeNode b){
        int res=0;
        while(a!=b){
            if(level.get(a)>level.get(b)){a=par.get(a);res+=1;}
            else if(level.get(b)>level.get(a)){b=par.get(b);res+=1;}
            else{a=par.get(a);b=par.get(b);res+=2;}
        }
        return res;
    }
    public int countPairs(TreeNode root, int distance) {
        dfs(root,null,0);
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                int d=getDis(arr.get(i),arr.get(j));
                if(d<=distance){cnt+=1;}
            }
        }
        return cnt;
    }
}