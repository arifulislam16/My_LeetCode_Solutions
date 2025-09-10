/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
   
    public int maxDepth(Node root) {
      int res=0;
      Queue<Node>q=new LinkedList<Node>();
      q.add(root);
      if(root==null){return 0;}
      while(q.size()>0){
          int sz=q.size();
          while(sz>0){
              Node cur=q.peek();q.remove(q.peek());
              for(Node child:cur.children){
                  if(child!=null){
                      q.add(child);
                  }
              }
              sz-=1;
          }
          res++;
      }
      return res;
    }
}