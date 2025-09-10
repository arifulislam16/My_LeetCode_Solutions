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
void dfs(TreeNode* root,vector<int>&v){
    if(root==nullptr){return;}
    dfs(root->left,v);
    v.emplace_back(root->val);
    dfs(root->right,v);
    return;
}
void getMerge(vector<int>& v,int b,int mid,int e){

  int i=b,j=mid+1;
  vector<int>tmp;
  while(i<=mid&&j<=e){
    if(v[i]<v[j]){tmp.push_back(v[i++]);}
    else{tmp.push_back(v[j++]);}
  }
  while(i<=mid){tmp.push_back(v[i++]);}
  while(j<=e){tmp.push_back(v[j++]);}
  i=b,j=0;
  while(i<=e){
    v[i++]=tmp[j++];
  }
  return;
}
void cnt(int b,int e,vector<int>& v){
   if(b>e){return;}
   if(b==e){return;}
   int mid=b+(e-b)/2;
   cnt(b,mid,v);
   cnt(mid+1,e,v);
   getMerge(v,b,mid,e);
    return;
}
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>v;
        dfs(root1,v);
        dfs(root2,v);
        cnt(0,v.size()-1,v);
        for(auto&val:v){cout<<val<<" ";}

        return v;
    }
};