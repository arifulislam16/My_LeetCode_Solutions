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
    void dfs(TreeNode* root){
        if(root==nullptr){return ;}
        dfs(root->left);
        v.emplace_back(root->val);
        dfs(root->right);
        return;
    }
    void dfs2(TreeNode* root,int pre[]){
        if(root==nullptr){return;}
        // 0 1 2 3 4 5 6 7 8
        int pos=upper_bound(v.begin(),v.end(),root->val)-v.begin();
        int sum=pre[v.size()-1]-pre[pos-1];
        root->val+=sum;
        dfs2(root->left,pre);
        dfs2(root->right,pre);
    }
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);
        int sz=v.size();int pre[sz];
        pre[0]=v[0];
        for(int i=1;i<v.size();i++){pre[i]=pre[i-1]+v[i];}
        dfs2(root,pre);
        return root;
    }
};