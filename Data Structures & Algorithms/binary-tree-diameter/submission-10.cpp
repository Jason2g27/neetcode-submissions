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
    int maxDiam = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        traverse(root);
        return maxDiam;
    }

    int traverse(TreeNode* node){
        if(!node){
            return 0;
        }
        int left = traverse(node->left);
        int right = traverse(node->right);
        maxDiam = max(maxDiam, left + right);
        return max(left, right)+1;
    }
};
