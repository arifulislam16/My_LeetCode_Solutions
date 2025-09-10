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
void dfs(TreeNode* root,TreeNode*p,
vector<TreeNode*> &res,vector<TreeNode*>&v){
    if(root==nullptr){return ;}
    v.emplace_back(root);
    if(root->val==p->val){res=v;return ;}
    dfs(root->left,p,res,v);
    dfs(root->right,p,res,v);
    v.pop_back();
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>v1,v;
        dfs(root,p,v1,v);
        vector<TreeNode*>v2;
        v.clear();
        dfs(root,q,v2,v);
        TreeNode* res=nullptr;
    for(int i=0;i<min(v1.size(),v2.size());i++){
        if(v1[i]->val==v2[i]->val){res=v1[i];}
        else break;
    }
    return res;

    }
};