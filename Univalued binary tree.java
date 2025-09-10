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
    boolean dfs(TreeNode root,int tar){
        if(root==null){return true;}
        if(root.val!=tar){return false;}
        boolean ok=dfs(root.left,tar);
        ok&=dfs(root.right,tar);
        return ok;
    }
    public boolean isUnivalTree(TreeNode root) {
        int val=root.val;
        return dfs(root,val);
    }
}