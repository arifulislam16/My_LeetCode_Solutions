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
void dfs(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&par,int &res){
    if(root==nullptr){return ;}
    if(par[root]!=nullptr&&par[par[root]]!=nullptr&&par[par[root]]->val%2==0){
        res+=root->val;
        
    }
    if(root->left){
        par[root->left]=root;
        dfs(root->left,par,res);
    }
    if(root->right){
        par[root->right]=root;
        dfs(root->right,par,res);
    }
}
    int sumEvenGrandparent(TreeNode* root) {
        int res=0;
        unordered_map<TreeNode*,TreeNode*>par;
        par[root]=nullptr;
        dfs(root,par,res);
        return res;
        return 0;
    }
};