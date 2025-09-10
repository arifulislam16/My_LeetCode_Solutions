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
    int sum=0,dep=0;
    void dfs(TreeNode root,int curDep){
        if(root==null){return ;}
        if(curDep==dep){sum+=root.val;}
        if(curDep>dep){dep=curDep;sum=root.val;}
        if(root.left!=null){dfs(root.left,curDep+1);}
        if(root.right!=null){dfs(root.right,curDep+1);}
    }
    public int deepestLeavesSum(TreeNode root) {
        int curDep=0;
        dfs(root,curDep);
        return sum;
    }
}