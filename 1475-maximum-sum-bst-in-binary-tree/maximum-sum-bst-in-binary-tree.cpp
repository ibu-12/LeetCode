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
    int maxSum;
    struct Result
    {
        bool isBST;
        int sum;
        int minval;
        int maxval;
    };
    Result helper(TreeNode* root)
    {
        if(root==NULL)
        {
            return {true,0,INT_MAX,INT_MIN};
        }
        Result left=helper(root->left);
        Result right=helper(root->right);
        if(left.isBST && right.isBST && root->val>left.maxval && root->val<right.minval)
        {
            int cursum=root->val + left.sum+right.sum;
            maxSum=max(maxSum,cursum);
            return {true, cursum, min(root->val, left.minval), max(root->val, right.maxval)};
        }
        else
        {
            return {false,0,0,0};
        }
    }
    int maxSumBST(TreeNode* root) 
    {
        maxSum=0;
        Result res= helper(root);
        return maxSum;
    }
};