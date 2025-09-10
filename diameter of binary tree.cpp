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
    int max(int a,int b){return (a>b)?a:b;}
    int  dfs(TreeNode root){
        if(root==null){return 0;}
        if(root.left==null&&root.right==null){return 1;}
        int l=dfs(root.left);
        int r=dfs(root.right);
        res=max(res,l+r);
        return max(l,r)+1;
    }
    public int diameterOfBinaryTree(TreeNode root) {
        dfs(root);
        return res;
    }
}