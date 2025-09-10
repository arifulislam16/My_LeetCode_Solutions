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
bool dfs(TreeNode* root){
    if(!root->left&&!root->right){return root->val;}
    bool op1=dfs(root->left);
    bool op2=dfs(root->right);
    if(root->val==2){return op1|op2;}
    return op1&op2;
}
    bool evaluateTree(TreeNode* root) {
        /// leaf node 0 false, 1 true
        //  non leaf 2 or, 3 and 
        // node has 2 or  0 children;
        if(!root->left&&!root->right){return root->val;}
        return dfs(root);
    }
};