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
unordered_map<int,TreeNode*>mp;
TreeNode* sor=nullptr;
unordered_map<TreeNode*,TreeNode*>par;
void dfs(TreeNode*root, TreeNode*p,int start){
    if(root==nullptr){return ;}
    par[root]=p;
    if(root->val==start){sor=root;}
    if(root->left){dfs(root->left,root,start);}
    if(root->right){dfs(root->right,root,start);}
    return;
}
    int amountOfTime(TreeNode* root, int start) {
               dfs(root,nullptr,start);
              int res=0;
              queue<pair<TreeNode*,int>>q;q.push({sor,0});
              unordered_map<int,int>visit;
              visit[start]++;
              while(q.size()){
                  int sz=q.size();
                  while(sz-->0){
                      pair<TreeNode*,int>tmp=q.front();q.pop();
                      res=max(res,tmp.second);
                      TreeNode* node=tmp.first;
                      if(node->left&&!visit[node->left->val]){
                          q.push({node->left,tmp.second+1});
                          visit[node->left->val]++;
                      }
                      if(node->right&&!visit[node->right->val]){
                          q.push({node->right,tmp.second+1});
                          visit[node->right->val]++;
                      }
                      if(par[node]&&!visit[par[node]->val]){
                          q.push({par[node],tmp.second+1});
                          visit[par[node]->val]++;
                      }
                  }
              }
              return res;

    }
};