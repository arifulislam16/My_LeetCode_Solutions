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
    void dfs(TreeNode root,int dep[],HashMap<Integer,Integer>par,int d){
        if(root==null){return ;}
        dep[root.val]=d;
        if(root.left!=null){
            par.put(root.left.val,root.val);
            dfs(root.left,dep,par,d+1);
        }
        if(root.right!=null){
            par.put(root.right.val,root.val);
            dfs(root.right,dep,par,d+1);
        }
        return ;
    }
    public boolean isCousins(TreeNode root, int x, int y) {
        int dep[]=new int[101];
        dep[root.val]=0;
        HashMap<Integer,Integer>par=new HashMap<Integer,Integer>();
        par.put(root.val,root.val);
        dfs(root,dep,par,0);
        return (dep[x]==dep[y])&&(par.get(x)!=par.get(y));
    }
}