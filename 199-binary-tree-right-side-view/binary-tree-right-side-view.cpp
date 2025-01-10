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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> c;
        if (root == nullptr)
            return vector<int>();

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            int l=1;
            for (int i = 0; i < s; i++) {
                TreeNode* curr = q.front();
                if(l==1) c.push_back(curr->val);
                   
                q.pop();

                if (curr->right)
                    q.push(curr->right);
                if (curr->left)
                    q.push(curr->left);
                l++;
            }
        }
        return c;
    }
};