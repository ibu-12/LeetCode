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
    void rec(TreeNode* root,int depth,vector<int>&ans)
    {
        if(root==nullptr)
          return;
        if(depth==ans.size())
           ans.push_back(root->val);
        rec(root->right,depth+1,ans);
        rec(root->left,depth+1,ans);
    }
    vector<int> rightSideView(TreeNode* root)
    {
        if(root==nullptr)
          return {};
        vector<int>ans;
        rec(root,0,ans);
        return ans;
        
    }
};