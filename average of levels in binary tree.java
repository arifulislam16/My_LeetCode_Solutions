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
    public List<Double> averageOfLevels(TreeNode root) {
        ArrayList<Double>arr=new ArrayList<Double>();
        Queue<TreeNode>q=new LinkedList<TreeNode>();
        q.add(root);
        while(q.size()>0){
            int sz=q.size();
            Double ans=0.0;
            int cnt=0;
            while(sz>0){
                TreeNode cur=q.poll();
                ans+=cur.val;
                cnt+=1;
                if(cur.left!=null){q.add(cur.left);}
                if(cur.right!=null){q.add(cur.right);}
                sz--;
            }
            arr.add(ans/(double)cnt);
        }
        return arr;
    }
}