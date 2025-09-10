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
    void dfs(TreeNode root,List<Integer>arr){
        if(root==null){return;}
        dfs(root.left,arr);
        arr.add(root.val);
        dfs(root.right,arr);
        return;
    }
    void merge(int b,int mid,int e,List<Integer>arr){
        int i=b,j=mid+1;
        List<Integer>tmp=new ArrayList<Integer>();
        while(i<=mid&&j<=e){
            if(arr.get(i)<=arr.get(j)){tmp.add(arr.get(i));i++;}
            else{tmp.add(arr.get(j));j++;}
        }
        while(i<=mid){tmp.add(arr.get(i));i++;}
        while(j<=e){tmp.add(arr.get(j));j++;}
        i=b;j=0;
        while(i<=e){
            arr.set(i,tmp.get(j));
            i++;j++;
        }
        return;
    }
    void cnt(int b,int e,List<Integer>arr){
        if(b>=e){return;}
        int mid=b+(e-b)/2;
        cnt(b,mid,arr);
        cnt(mid+1,e,arr);
        merge(b,mid,e,arr);
        return;
    }
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        List<Integer>v=new ArrayList<Integer>();
        dfs(root1,v);
        dfs(root2,v);
        cnt(0,v.size()-1,v);
        return v;
    }
}