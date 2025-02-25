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

    int fun(TreeNode* root,int v){
        if(!root)return 0;
        int n=v;
        int c=0;
        if(root->val>=v){
            c=1;
            n=root->val;
        }
        c+=fun(root->left,n);
        c+=fun(root->right,n);
        return c;
    }

    int goodNodes(TreeNode* root) {
        return fun(root,root->val);
    }
};