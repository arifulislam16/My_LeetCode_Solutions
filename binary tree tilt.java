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
    int sum=0;
    int abs(int a){
        if(a<0){return -a;}
        return a;
    }
    int dfs(TreeNode root){
        if(root==null){return 0;}
        int l=dfs(root.left);
        int r=dfs(root.right);
        sum+=abs(l-r);
        return l+r+root.val;
    }
    public int findTilt(TreeNode root) {
        if(root==null){return sum;}
        dfs(root);
        return sum;
    }
}