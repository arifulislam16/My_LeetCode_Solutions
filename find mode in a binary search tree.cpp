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
vector<int>res;
int count=0;
unordered_map<int,int>mp;
int max(int a,int b){return (a>b)?a:b;}
void dfs(TreeNode* root){
    if(root==nullptr){return;}
    mp[root->val]++;
    count=max(count,mp[root->val]);
    dfs(root->left);
    dfs(root->right);
    return;
}
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        for(pair<int,int>p:mp){
            if(p.second==count){res.emplace_back(p.first);}
        }
        return res;
    }
};