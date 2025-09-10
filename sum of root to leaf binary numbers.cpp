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
void dfs(TreeNode* root,string res,vector<string>&v){
    if(root==nullptr){return;}
    res+=(root->val==1)?"1":"0";
    if(root->left==nullptr&&root->right==nullptr){v.push_back(res);}
    dfs(root->left,res,v);
    dfs(root->right,res,v);
    res.pop_back();
    return;
}
int getSum(string& s){
   int sum=0;
   for(int i=0,j=s.size()-1;i<s.size();i++,j--){
      if(s[j]=='0'){continue;}
      sum+=pow(2,i);
   }
   return sum;
}
    int sumRootToLeaf(TreeNode* root) {
      string res=""   ;
      vector<string>v;
      dfs(root,res,v);
      //for(string str:v){cout<<str<<" \n";}
      int sum=0;
      for(string str:v){
        sum+=getSum(str);
      }
      return sum;
      return 0;
    }
};