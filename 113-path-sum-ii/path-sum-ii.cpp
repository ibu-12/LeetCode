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
    std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
        std::vector<std::vector<int>> result;
        backtrack(root, targetSum, {}, result);
        return result;
    }

    void backtrack(TreeNode* root, int targetSum, std::vector<int> currentlist, std::vector<std::vector<int>>& result) {
        if (root == nullptr) {
            return;
        }
        currentlist.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && root->val == targetSum) {
            result.push_back(currentlist);
        } else {
            backtrack(root->left, targetSum - root->val, currentlist, result);
            backtrack(root->right, targetSum - root->val, currentlist, result);
        }
        currentlist.pop_back();
    }
};