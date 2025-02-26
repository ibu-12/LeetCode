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
    int c=0;
    int ans;
    void small(TreeNode* root, int k){
        if(!root)return ;
        kthSmallest(root->left,k);
        c++;
        if(c==k){
            ans=root->val;
            return;
        }
        kthSmallest(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        small(root,k);
        return ans;
    }
};