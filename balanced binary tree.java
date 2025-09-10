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
int max(int a,int b){return (a>b)?a:b;}
int abs(int a){if(a<0){return -a;}return a;}
boolean ok=true;
int dfs(TreeNode root){
    if(root==null){return 0;}
    if(root.left==null&&root.right==null){return 1;}
    int l=dfs(root.left);
    int r=dfs(root.right);
    if(abs(l-r)>1){ok=false;}
    return  max(l,r)+1;
}
    public boolean isBalanced(TreeNode root) {
     dfs(root)  ;
     return ok;
    }
}