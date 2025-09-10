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
    public static int min(int a,int b){return (a<b)?a:b;}
    void dfs(TreeNode root,ArrayList<Integer>v){
        if(root==null){return ;}
        dfs(root.left,v);
        v.add(root.val);
        dfs(root.right,v);
    }
    public int getMinimumDifference(TreeNode root) {
        ArrayList<Integer>v=new ArrayList<Integer>();
        dfs(root,v);
        int res=10000009;
        for(int i=0;i<v.size()-1;i++){
            res=min(res,v.get(i+1)-v.get(i));
        }
        return res;
    }
}