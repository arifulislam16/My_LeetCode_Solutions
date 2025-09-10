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
TreeNode* dfs(TreeNode* root,int tar){
   if(root==nullptr){return nullptr;}
   if(root->left==nullptr&&root->right==nullptr){
       if(root->val==tar){return nullptr;}
       else{return root;}
   }
   root->left=dfs(root->left,tar);
   root->right=dfs(root->right,tar);
   if(root->left==nullptr&&root->right==nullptr&&root->val==tar){
       return nullptr;
   }
   else{return root;}
}
bool isleaf(TreeNode* root){
    return root->left==nullptr&&root->right==nullptr;
}
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
       TreeNode* tmp=dfs(root,target);
       if(tmp==nullptr){return nullptr;}
       if(isleaf(tmp)&&tmp->val==target){return nullptr;}
       return tmp;
    }
};