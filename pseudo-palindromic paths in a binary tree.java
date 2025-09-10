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
    HashMap<Integer,Integer>mp=new HashMap<Integer,Integer>();
    int res=0;
    boolean isLeaf(TreeNode root){
        if(root.left==null&&root.right==null){return true;}
        return false;
    }
    void ok(){
        int sz=0,odd=0,even=0;
        for(Integer i:mp.keySet()){
            int key=i,value=mp.get(i);
            if(value>0){
                sz+=value;
                if(value%2==1){odd+=1;}
                else{even+=1;}
            }
        }
        if(sz%2==1){if(odd==1){res++;}}
        else{if(odd==0){res++;}}
    }
    void dfs(TreeNode root){
        if(root==null){return;}
        if(mp.containsKey(root.val)){
            mp.put(root.val,mp.get(root.val)+1);
        }
        else{mp.put(root.val,1);}
        if(isLeaf(root)){
            ok();
        }
        if(root.left!=null){dfs(root.left);}
        if(root.right!=null){dfs(root.right);}
        mp.put(root.val,mp.get(root.val)-1);
        return;
    }
    public int pseudoPalindromicPaths (TreeNode root) {
        dfs(root);
        return res;
    }
}