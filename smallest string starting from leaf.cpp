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
   unordered_map<int,char>mp;
   set<string>st;
   

   bool isleaf(TreeNode* root){
       return (!root->left&&!root->right);
   }
   string get(string s){
              string tmp="";
              for(int i=s.size()-1;i>=0;i--){tmp+=s[i];}
              return tmp;
   }
   void dfs(TreeNode* root,string tmp){
       if(root==nullptr){return ;}
       tmp+=mp[root->val];
       if(isleaf(root)){
           string s=get(tmp);
           st.insert(s);
           return;
       }
       if(root->left){dfs(root->left,tmp);}
       if(root->right){dfs(root->right,tmp);}
       tmp.pop_back();
   }
    string smallestFromLeaf(TreeNode* root) {
            int i=0;
            for(char ch='a';ch<='z';ch++){
                mp[i++]=ch;
            }
            dfs(root,"");
            return *(st.begin());
    }
};