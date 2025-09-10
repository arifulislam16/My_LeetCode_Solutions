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
int mx=0;
int lsum[20005]={0};
int max(int a,int b){return (a>b)?a:b;}
int min(int a,int b){return (a<b)?a:b;}
void dfs(TreeNode* root,int d){
    if(root==nullptr){return ;}
    lsum[d]+=root->val;
    mx=max(mx,d);
    if(root->left){dfs(root->left,d+1);}
    if(root->right){dfs(root->right,d+1);}
    return;
}
    int maxLevelSum(TreeNode* root) {
        dfs(root,1);
        int l=1e9,sum=-1e9;
    
        for(int i=1;i<=mx;i++){
            if(sum<lsum[i]){
                sum=lsum[i];
                l=i;
            }
            else if(sum==lsum[i]){
                l=min(l,i);
            }
        }
        return l;
    }
};