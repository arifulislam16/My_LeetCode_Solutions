/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        int res=0;
        queue<Node*>q;
        if(root==nullptr){return 0;}
        q.push(root);
        while(q.size()){
            int sz=q.size();
            while(sz--){
                Node* cur=q.front();q.pop();
                for(auto child:cur->children){
                    if(child!=nullptr){
                        q.push(child);
                    }
                }
            }
            res++;
        }
        return res;
    }
};