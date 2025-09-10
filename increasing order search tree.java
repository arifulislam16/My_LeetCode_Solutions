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
    void dfs(TreeNode root,ArrayList<Integer>v){
        if(root==null){return ;}
        dfs(root.left,v);
        v.add(root.val);
        dfs(root.right,v);
        return ;
    }
    public TreeNode increasingBST(TreeNode root) {
        ArrayList<Integer>v=new ArrayList<Integer>();
        dfs(root,v);
        TreeNode root1=new TreeNode(v.get(0));
        root1.left=root1.right=null;
        TreeNode tmp=root1;
        for(int i=1;i<v.size();i++){
            TreeNode t=new TreeNode(v.get(i));
            t.left=null;
            tmp.right=t;
            tmp=t;
        }
        return root1;
    }
}