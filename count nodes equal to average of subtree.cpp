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
 int res=0;
 pair<int,int>dfs(TreeNode* root){
     if(root==nullptr){return {0,0};}
     if(root->left==nullptr&&root->right==nullptr){
         cout<<root->val<<" : "<<"(leaf):  "<<1<<" : "<<root->val<<"\n";
         res+=1;
         return {1,root->val};
     }
     pair<int,int>l=dfs(root->left);
     pair<int,int>r=dfs(root->right);
     int avg=(l.second+r.second+root->val)/(l.first+r.first+1);
     if(avg==root->val){res++;}
     cout<<root->val<<" "<<"(left):"<<l.first<<" ,"<<l.second<<" | ";
     cout<<"(right):"<<r.first<<" ,"<<r.second<<"\n";
     return {l.first+r.first+1,l.second+r.second+root->val};
 }
    int averageOfSubtree(TreeNode* root) {
     pair<int,int>   p=dfs(root);
        cout<<p.first<<" "<<p.second<<"\n";
        return res;
    }
};