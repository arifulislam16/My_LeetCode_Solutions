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
    int []dfs(TreeNode root){
        if(root==null){
            return new int[]{0,0};
        }
        if(root.left==null&&root.right==null){
            sum++;
            return new int[]{1,root.val};
        }
        int l[]=dfs(root.left);
        int r[]=dfs(root.right);
        int avg=(l[1]+r[1]+root.val)/(l[0]+r[0]+1);
        if(avg==root.val){sum+=1;}
        return new int[]{l[0]+r[0]+1,l[1]+r[1]+root.val};
    }
    public int averageOfSubtree(TreeNode root) {
        dfs(root);
        return sum;
    }
}