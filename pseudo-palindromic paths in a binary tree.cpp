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
unordered_map<int,int>mp;
int res=0;
void ok(){
    int sz=0,odd=0,even=0;
   // cout<<"\n";
    for(pair<int,int>p:mp){
        if(p.second){
        //    cout<<"val:"<<p.first<<",count:"<<p.second;
            cout<<'\n';
            (p.second&1)?odd++:even++;
            sz+=p.second;
        }
    }
   // cout<<"\n";
    if(sz&1){if(odd==1){res++;}}
    else{if(odd==0){res++;}}
    return;
}
bool isleaf(TreeNode* root){
   if(!root->left&&!root->right){return true;}
   return false;
}
void dfs(TreeNode* root){
    if(root==nullptr){return ;}
    mp[root->val]++;
    if(isleaf(root)){
        ok();
    }
    if(root->left){dfs(root->left);}
    if(root->right){dfs(root->right);}
    mp[root->val]--;
}
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);
        return res;
    }
};