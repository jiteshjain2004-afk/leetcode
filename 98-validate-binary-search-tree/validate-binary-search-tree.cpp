class Solution {
public:
    TreeNode* prev = NULL;

    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;

        // Check left subtree
        if (!isValidBST(root->left))
            return false;

        // Check current node
        if (prev != NULL && root->val <= prev->val)
            return false;

        prev = root;

        // Check right subtree
        if (!isValidBST(root->right))
            return false;

        return true;
    }
};