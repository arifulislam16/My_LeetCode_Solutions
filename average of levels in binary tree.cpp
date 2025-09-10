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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>res;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            int sz=q.size();
            double ans=0;
            int cnt=0;
            while(sz-->0){
                
                
                TreeNode* cur=q.front() ;q.pop();
                ans+=(double)cur->val;
                cnt+=1;
                if(cur->left){q.push(cur->left);}
                if(cur->right){q.push(cur->right);}
            }
            res.emplace_back(ans/(double)cnt);
        }
        return res;
    }
};