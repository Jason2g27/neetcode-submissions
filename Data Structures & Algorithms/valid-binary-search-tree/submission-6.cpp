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
    bool isValidBST(TreeNode* root) {
        return traverse(root, INT_MIN, INT_MAX);
    }

    bool traverse(TreeNode* root, int min, int max){
        if(!root){
            return true;
        }
        if (!(min < root->val && root->val < max)) {
            return false;
        }
        return traverse(root->left, min, root->val) && traverse(root->right, root->val, max);
    }
};
