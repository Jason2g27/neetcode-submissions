class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // If checkHeight returns -1, the tree is unbalanced
        return checkHeight(root) != -1;
    }

private:
    int checkHeight(TreeNode* root) {
        // Base case: an empty tree has a height of 0
        if (root == nullptr) {
            return 0;
        }

        // 1. Check the height of the left subtree
        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1) return -1; // Left subtree is unbalanced

        // 2. Check the height of the right subtree
        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1) return -1; // Right subtree is unbalanced

        // 3. Check if the current node is balanced
        if (abs(leftHeight - rightHeight) > 1) {
            return -1; // Current node is unbalanced
        }

        // 4. Return the actual height if balanced
        return 1 + max(leftHeight, rightHeight);
    }
};