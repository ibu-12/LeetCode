class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root; 

        if (root->val == key) {
            if (root->right) {
                TreeNode* temp = root->right;
                while (temp->left) temp = temp->left; 
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val); 
            }
            else if (root->left) {
                TreeNode* temp = root->left;
                while (temp->right) temp = temp->right; 
                root->val = temp->val;
                root->left = deleteNode(root->left, temp->val); 
            }
            else {
                delete root;
                return nullptr;
            }
        } 
        else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } 
        else {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
};