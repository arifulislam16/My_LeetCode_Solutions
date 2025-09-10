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
bool ok(TreeNode*r1,TreeNode*r2){
    if(!r1&&!r2){return true;}
    if(!r1||!r2){return false;}
    if(r1->val!=r2->val){return false;}
    return ok(r1->left,r2->left)&&ok(r1->right,r2->right);
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr&&subRoot==nullptr){return true;}
        if(root==nullptr||subRoot==nullptr){return false;}
        if(ok(root,subRoot)){return true;}
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};