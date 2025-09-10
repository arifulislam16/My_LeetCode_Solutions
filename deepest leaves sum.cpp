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
int dep=0,sum=0;
void dfs(TreeNode* root,int curDep){
    if(root==nullptr){return ;}
    if(curDep==dep){sum+=root->val;}
    if(curDep>dep){sum=root->val;dep=curDep;}
    if(root->left){
        dfs(root->left,curDep+1);
    }
    if(root->right){
        dfs(root->right,curDep+1);
    }
}
    int deepestLeavesSum(TreeNode* root) {
        int curDep=0;
        dfs(root,curDep);
        return sum;
    }
};