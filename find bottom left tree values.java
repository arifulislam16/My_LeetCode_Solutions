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
    public int findBottomLeftValue(TreeNode root) {
        int res=0;
        Queue<TreeNode>q=new LinkedList<TreeNode>();
        q.add(root);
        while(q.size()>0){
            int sz=q.size();
            TreeNode first=null;
            while(sz-->0){
                TreeNode cur=q.peek();q.remove(q.peek());
                if(first==null){first=cur;}
                if(cur.left!=null){q.add(cur.left);}
                if(cur.right!=null){q.add(cur.right);}
            }
            if(first!=null){res=first.val;}
        }
        return res;
    }
}