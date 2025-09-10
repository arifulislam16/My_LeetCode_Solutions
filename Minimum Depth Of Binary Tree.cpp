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
    int h=99999;
    void dfs(TreeNode* root,int hi){
        if(root==nullptr){return ;}
if(root->left==nullptr&&
root->right==nullptr){
    h=min(h,hi);return ;
}
dfs(root->left,hi+1);
dfs(root->right,hi+1);
return ;
    }
    int minDepth(TreeNode* root) {
        if(root==nullptr){return 0;}
        dfs(root,1);
        return h;
    }
};