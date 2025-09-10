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

    TreeNode* replaceValueInTree(TreeNode* root) {
            root->val=0;
            queue<TreeNode*>q;
            q.push(root);
            while(q.size()>0){
                int sz=q.size();
                int sum=0;
                vector<TreeNode*>tmp;
                while(sz-->0){
                    TreeNode* cur=q.front();q.pop();
                    tmp.push_back(cur);
                    if(cur->left){
                        sum+=cur->left->val;
                        q.push(cur->left);
                    }
                    if(cur->right){
                        sum+=cur->right->val;
                        q.push(cur->right);
                    }
                }
                for(TreeNode* node:tmp){
                      int tsum=0;
                      if(node->left){tsum+=node->left->val;}
                      if(node->right){tsum+=node->right->val;}
                      if(node->left){
                          node->left->val=sum-tsum;
                      }
                      if(node->right){
                          node->right->val=sum-tsum;
                      }
                }
            }
            return root;
    }
};