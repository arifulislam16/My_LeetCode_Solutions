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
    vector<string>v;
    typedef long long ll;
    void dfs(TreeNode* root,string s){
        if(root==nullptr){return ;}
        s+=to_string(root->val);
        if(root->left==nullptr&&
        root->right==nullptr){
            v.emplace_back(s);
        }
        dfs(root->left,s);
        dfs(root->right,s);
        s.pop_back();
    }
    ll getans(string &s){
        ll ans=0;
        for(int i=0;i<s.size();i++){
            ans=(ans*10)+(s[i]-'0');
        }
        return ans;
    }
    int sumNumbers(TreeNode* root) {
        dfs(root,"");
        ll ans=0LL;
        for(string str:v){
            ans+=getans(str);
        }
        return ans;
    }
};