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
int h=0;
void dfs(TreeNode* root,int hi){
   if(root==nullptr){return ;}
   //res.emplace_back(root->val);
   if(hi>h){res.push_back(root->val);
   h=hi;}
   dfs(root->right,hi+1);
   dfs(root->left,hi+1);
   
   
}
    vector<int> rightSideView(TreeNode* root) {
        dfs(root,1);
        return res;
    }
};