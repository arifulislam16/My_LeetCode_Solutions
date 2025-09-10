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
    boolean dfs(TreeNode root){
        if(root.left==null&&root.right==null){return (root.val==0)?false:true;}
        boolean op1=dfs(root.left);
        boolean op2=dfs(root.right);
        if(root.val==2){return op1|op2;}
        return op1&op2;
    }
    public boolean evaluateTree(TreeNode root) {
        // node has 2 or 0 children
        // leaf node  0(false),1(true);
        // node has 2(or) ,3(and);
        if(root.left==null&&root.right==null){return (root.val==0)?false:true;}
        return dfs(root);
    }
}