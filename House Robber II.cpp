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
map<pair<TreeNode*,int>,int >mp;
   int dfs(TreeNode* root,int t){
       if(root==nullptr){return 0;}
       if(mp.find({root,t})!=mp.end()){
           return mp[{root,t}];
       }
       if(t==0){
           int a=dfs(root->left,1);
           int b=dfs(root->right,1);
           int c=dfs(root->left,0);
           int d=dfs(root->right,0);
           int p1=a+b+root->val;
           int p2=c+d;
           mp[{root,t}]=max(p1,p2);
           return max(p1,p2);
       }
       else{
            int a=dfs(root->left,0)         ;
            int b=dfs(root->right,0);
            mp[{root,t}]=a+b;
            return a+b;
       }
   }
    int rob(TreeNode* root) {
       int a=dfs(root->left,1);
       int b=dfs(root->right,1);
       int c=dfs(root->left,0);
       int d=dfs(root->right,0);
       int ans1=a+b+root->val;
       int ans2=c+d;
       return max(ans1,ans2);
    }
};