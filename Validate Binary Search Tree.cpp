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
    vector<int>v;
    void dfs(TreeNode*root){
        if(root==nullptr){return ;}
        dfs(root->left);
        v.emplace_back(root->val);
        dfs(root->right);
        return ;
    }
    bool isValidBST(TreeNode* root) {
        dfs(root);
        for(int i=0;i<v.size()-1;i++){
            if(v[i]<v[i+1]){continue;}
            else{return false;}
        }
        return true;
    }
};