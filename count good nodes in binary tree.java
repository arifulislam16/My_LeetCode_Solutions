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
    int cnt=0;
    void dfs(TreeNode root,int tmx){
        if(root==null){return ;}
        if(root.val==tmx){cnt+=1;}
        if(root.val>tmx){cnt+=1;
        tmx=root.val;}
        if(root.left!=null){
            dfs(root.left,tmx);
        }
        if(root.right!=null){
            dfs(root.right,tmx);
        }
    }
    public int goodNodes(TreeNode root) {
        //int cnt=0;
        dfs(root,root.val);
        return cnt;
    }
}