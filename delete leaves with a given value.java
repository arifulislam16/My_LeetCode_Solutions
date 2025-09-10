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
    boolean isleaf(TreeNode root){
        if (root.left==null&&root.right==null){return true;}
        else{
        return false;
        }
    }
    TreeNode dfs(TreeNode root,int tar){
        if(root==null){return null;}
        if(isleaf(root)&&root.val==tar){return null;}
        root.left=dfs(root.left,tar);
        root.right=dfs(root.right,tar);
        if(root.left==null&&root.right==null&&root.val==tar){return null;}
        else{return root;}
    }
    public TreeNode removeLeafNodes(TreeNode root, int target) {
        if(root==null){return null;}
        TreeNode tmp=dfs(root,target);
        if(tmp==null){return null;}
        if(isleaf(tmp)&&root.val==target){return null;}
        return tmp;
    }
}