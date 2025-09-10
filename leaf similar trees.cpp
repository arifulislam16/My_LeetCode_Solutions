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
    int sum=0;
    int abs(int a){
        if(a<0){return -a;}
        return a;
    }
    int dfs(TreeNode* root){
        if(root==nullptr){return 0;}
        int l=dfs(root->left);
        int r=dfs(root->right);
        sum+=abs(l-r);
        return root->val+l+r;
    }
    int findTilt(TreeNode* root) {
        if(root==nullptr){return sum;}
        dfs(root);
        return sum;
    }
};