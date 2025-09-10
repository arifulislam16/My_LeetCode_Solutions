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
    int res=0;
    void dfs(TreeNode root,HashMap<TreeNode,TreeNode>par){
        if(root==null){return ;}
        if(par.get(root)!=null&&par.get(par.get(root))!=null){
            if(par.get(par.get(root)).val%2==0){
                System.out.print(root.val+" ");
            res+=root.val;
            }
        }
        if(root.left!=null){
            par.put(root.left,root);
            dfs(root.left,par);
        }
        if(root.right!=null){
            par.put(root.right,root);
            dfs(root.right,par);
        }
        return ;
    }
    public int sumEvenGrandparent(TreeNode root) {
        HashMap<TreeNode,TreeNode>par=new HashMap<TreeNode,TreeNode>();
        par.put(root,null);
        
        dfs(root,par);
        return res;
    }
}