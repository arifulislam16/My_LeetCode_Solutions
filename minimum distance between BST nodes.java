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
    void dfs(TreeNode root,ArrayList<Integer>arr){
        if(root==null){return ;}
        dfs(root.left,arr);
        arr.add(root.val);
        dfs(root.right,arr);
    }
    public static int min(int a,int b){
        return (a<b)?a:b;
    }
    public int minDiffInBST(TreeNode root) {
        ArrayList<Integer>arr=new ArrayList<Integer>();
        dfs(root,arr);
        int res=10000009;
        for(int i=0;i<arr.size()-1;i++){
            res=min(res,arr.get(i+1)-arr.get(i));
        }
        return res;
    }
}