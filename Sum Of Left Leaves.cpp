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
int res=0;
bool isleaf(TreeNode* root){
    if(!root->left&&!root->right){return true;}
    return false;
}
void dfs(TreeNode* root){
    if(root==nullptr){return ;}
    if(root->left&&isleaf(root->left)){res+=root->left->val;}
    dfs(root->left);
    dfs(root->right);
}
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root);
        return res;
    }
};