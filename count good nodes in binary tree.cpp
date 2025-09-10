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
 void dfs(TreeNode* root,int tmx,int &cnt){
     if(root==nullptr){return ;}
     cout<<root->val<<" ,"<<tmx<<"-> ";
     if(root->val==tmx){cnt++;  }
     if(root->val>tmx){cnt+=1;}
     if(root->left){dfs(root->left,max(tmx,root->val),cnt);}
     if(root->right){dfs(root->right,max(tmx,root->val),cnt);}
 }
    int goodNodes(TreeNode* root) {
        int cnt=0;
        dfs(root,root->val,cnt);
        return cnt;
    }
};