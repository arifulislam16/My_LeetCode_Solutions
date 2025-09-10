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
void dfs(TreeNode* root,vector<int>&v){
    if(root==nullptr){return ;}
    dfs(root->left,v);
    v.emplace_back(root->val);
    dfs(root->right,v);
}
    int minDiffInBST(TreeNode* root) {
        vector<int>v;
        dfs(root,v);
        int res=1e9;
        for(int i=0;i<v.size()-1;i++){
            res=min(v[i+1]-v[i],res);
        }
        return res;
    }
};