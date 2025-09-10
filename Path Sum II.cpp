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
vector<vector<int>>res;
    void dfs(TreeNode* root,int sum,vector<int>&v){
        if(root==nullptr){return ;}
        v.emplace_back(root->val);
         if(root->left==nullptr&&root->right==nullptr){
            if(sum-root->val==0){res.emplace_back(v);}
        }
        dfs(root->left,sum-root->val,v);
        dfs(root->right,sum-root->val,v);
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>v;
        dfs(root,targetSum,v);
        return res;
    }
};