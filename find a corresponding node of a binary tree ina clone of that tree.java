/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    void dfs(TreeNode root,ArrayList<TreeNode>arr){
        if(root==null){return;}
        dfs(root.left,arr);
        arr.add(root);
        dfs(root.right,arr);
    }
    public final TreeNode getTargetCopy(final TreeNode original, final TreeNode cloned, final TreeNode target) {
        ArrayList<TreeNode>arr=new ArrayList<TreeNode>();
        dfs(cloned,arr);
        for(TreeNode tmp:arr){
            if(tmp.val==target.val){return tmp;}
        }
        return null;
    }
}