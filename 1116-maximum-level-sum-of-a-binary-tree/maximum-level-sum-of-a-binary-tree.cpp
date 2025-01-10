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
    int maxLevelSum(TreeNode* root) {
        

        queue<TreeNode*> q;
        q.push(root);
        int mx=INT_MIN;
        int ln;
        int l=0;
        while (!q.empty()) {
            int s = q.size();
            l++;
            int sum=0;
            for (int i = 1; i <= s; i++) {
                TreeNode* curr = q.front();
                   
                q.pop();
                sum+=curr->val;

                if (curr->right)
                    q.push(curr->right);
                if (curr->left)
                    q.push(curr->left);
            }
            if(mx<sum){
                mx=sum;
                ln=l;
            }
        }
        return ln;
    }
};