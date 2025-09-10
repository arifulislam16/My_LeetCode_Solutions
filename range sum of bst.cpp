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
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int>v;
        dfs(root,v);
        int b=lower_bound(v.begin(),v.end(),low)-v.begin();
        int e=upper_bound(v.begin(),v.end(),high)-v.begin();
        int sum=0;
        while(b<e){
            sum+=v[b++];

        }
        return sum;
    }
};