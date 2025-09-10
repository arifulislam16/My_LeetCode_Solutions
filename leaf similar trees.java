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
       if(root.left==null&&root.right==null){arr.add(root.val);return;}
       dfs(root.left,arr);
       dfs(root.right,arr);
       return;
   }
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        ArrayList<Integer>v1=new ArrayList<Integer>();
        ArrayList<Integer>v2=new ArrayList<Integer>();
        dfs(root1,v1);
        dfs(root2,v2);
        if(v1.size()!=v2.size()){return false;}
        for(int i=0;i<v1.size();i++){
            if(v1.get(i)!=v2.get(i)){return false;}
        }
        return true;
    }
}