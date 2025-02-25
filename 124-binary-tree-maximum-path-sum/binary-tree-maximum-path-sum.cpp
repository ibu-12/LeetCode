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
    int ans=INT_MIN;
    int fun(TreeNode *root){
        if(root==NULL)return 0;
        int l=max(0,fun(root->left));
        int r=max(0,fun(root->right));
        ans=max(ans,l+r+root->val);
        return max(l,r)+root->val;
    }

    int maxPathSum(TreeNode* root) {
        fun(root);
        return ans;
    }
};