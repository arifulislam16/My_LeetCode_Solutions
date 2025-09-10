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
  int count=0;
  int max(int a,int b){return (a>b)?a:b;}
  Map<Integer,Integer>mp=new HashMap<Integer,Integer>();
    void  dfs(TreeNode root){
      if(root==null){return;}
      if(mp.containsKey(root.val)){
          mp.put(root.val,mp.get(root.val)+1);
          count=max(count,mp.get(root.val));
      }
      else{
          mp.put(root.val,1);
          count=max(count,mp.get(root.val));
      }
      dfs(root.left);
      dfs(root.right);
      return;
  }
    public int[] findMode(TreeNode root) {
        dfs(root);
        int sz=0;
        for(Map.Entry<Integer,Integer>e:mp.entrySet())       {
            if(e.getValue()==count){sz++;}
        }
        int res[]=new int[sz];
        int i=0;
        for(Map.Entry<Integer,Integer>e:mp.entrySet()){
            if(e.getValue()==count){
                    res[i++]=e.getKey();
            }
        }
        return res;
    }
}