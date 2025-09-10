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
bool dfs(TreeNode* root,int tar){
    if(root==nullptr){return true;}
    if(root->val!=tar){return false;}
   // if(root==nullptr){return true;}
    bool ok=dfs(root->left,tar);
    ok&=dfs(root->right,tar);
    return ok;
}
    bool isUnivalTree(TreeNode* root) {
        if(root==nullptr){return true;}
        int val=root->val;
        return dfs(root,val);
    }
};