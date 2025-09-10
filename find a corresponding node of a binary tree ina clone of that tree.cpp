/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
void dfs(TreeNode* root,vector<TreeNode*>&v){
    if(root==nullptr){return ;}
    dfs(root->left,v);
    v.push_back(root);
    dfs(root->right,v);
    return;
}
    TreeNode* getTargetCopy(TreeNode* r1, TreeNode* r2, TreeNode* tar) {
       vector<TreeNode*>v;
       dfs(r2,v);
       for(TreeNode* tmp:v){
           if(tmp->val==tar->val){return tmp;}
       }
       return nullptr;
    }
};