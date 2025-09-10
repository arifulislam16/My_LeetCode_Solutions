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

    int findBottomLeftValue(TreeNode* root) {
       queue<TreeNode*>q;
       q.push(root);
       int res=0;
       while(q.size()){
           int sz=q.size();
           TreeNode* first=nullptr;
           while(sz--){
               TreeNode* cur=q.front();q.pop();
                if(first==nullptr){first=cur;}
                if(cur->left){q.push(cur->left);}
                if(cur->right){q.push(cur->right);}
           }
           if(first!=nullptr){res=first->val;}
       }
       return res;
    }
};