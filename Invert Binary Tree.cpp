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
TreeNode*  dfs(TreeNode* root){
    if(root==nullptr){return root;}
    if(root->left==nullptr&&root->right==nullptr){
        return root;
    }
    TreeNode* l=dfs(root->left);
    TreeNode* r=dfs(root->right);
    root->left=r;
    root->right=l;
    return root;
}
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* tmnp=dfs(root);
        return tmnp;
    }
};