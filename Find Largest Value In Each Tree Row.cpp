/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
       vector<int>res;
       if(root==nullptr){return res;}
       queue<TreeNode*>q;
       q.push(root);
       while(q.size()){
           int sz=q.size();
           int mx=INT_MIN;
           while(sz--){
               TreeNode*tmp=q.front();
               q.pop();
               mx=max(mx,tmp->val);
               if(tmp->left){
                   q.push(tmp->left);
               }
               if(tmp->right){
                   q.push(tmp->right);
               }
           }
           res.push_back(mx);
       }
       return res;
    }
};