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
    void dfs(TreeNode root,ArrayList<TreeNode>arr){
        if(root==null) {return ;}
        dfs(root.left,arr);
        arr.add(root);
        dfs(root.right,arr);
        return;
    }
    TreeNode cnt(int b,int e,ArrayList<TreeNode>arr){
        if(b>e){return null;}
       
        int mid=b+(e-b)/2;
        TreeNode tmp=arr.get(mid);
        tmp.left=cnt(b,mid-1,arr);
        tmp.right=cnt(mid+1,e,arr);
        return tmp;
    }
    public TreeNode balanceBST(TreeNode root) {
      ArrayList<TreeNode>arr=new ArrayList<TreeNode>();
      dfs(root,arr);
      TreeNode res=cnt(0,arr.size()-1,arr);
      return res;
    }
}