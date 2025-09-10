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
void dfs(TreeNode* root,unordered_map<int,int>&par,int dep[],int d,vector<int>&v){
    if(root==nullptr){return ;}
    dep[root->val]=d;
    v.emplace_back(root->val);
    if(root->left){
        par[root->left->val]=root->val;
        dfs(root->left,par,dep,d+1,v);
    }
    if(root->right){
        par[root->right->val]=root->val;
        dfs(root->right,par,dep,d+1,v);
    }
}
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int,int>par;
        vector<int>v;
        int dep[101]={0};
        dep[root->val]=0;
        par[root->val]=root->val;
        dfs(root,par,dep,0,v);
        for(int x:v){
            cout<<x<<" ,dep:"<<dep[x]<<",par:"<<par[x]<<"\n";
        }
        return  par[x]!=par[y]&&(dep[x]==dep[y]);
    }
};