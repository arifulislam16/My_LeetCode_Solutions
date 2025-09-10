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

    unordered_map<TreeNode*,TreeNode*>par;
    vector<int>res;
    unordered_map<TreeNode*,int>visit;
    void dfs(TreeNode* root,TreeNode* p){
        if(root==nullptr){return;}
        par[root]=p;
        if(root->left){dfs(root->left,root);}
        if(root->right){dfs(root->right,root);}
        return;
    }

    void dfs(TreeNode* root,int k){
        if(root==nullptr){return;}
        if(k==0){res.push_back(root->val);return;}
        if(k<0){return;}
        visit[root]++;
        if(root->left&&!visit[root->left]){dfs(root->left,k-1);}
        if(root->right&&!visit[root->right]){dfs(root->right,k-1);}
        if(par[root]&&!visit[par[root]]){dfs(par[root],k-1);}
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
      dfs(root,nullptr);
     // vector<int>res;
      dfs(target,k);
        return res;
    }
};