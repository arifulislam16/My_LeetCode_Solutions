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
    void dfs(TreeNode* root,vector<string>&res,string s){
        if(root->left==nullptr&&root->right==nullptr){res.push_back(s);return ;}
        if(root->left){
            dfs(root->left,res,s+"->"+to_string(root->left->val));
        }
        if(root->right){
            dfs(root->right,res,s+"->"+to_string(root->right->val));
        }
        return ;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
       vector<string>res;
        dfs(root,res,to_string(root->val));
        return res;
      ///  return {""};
    }
};