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
    int goodNodes(TreeNode* root) {
        int count = 0;
        traverse(root, count, root->val);
        return count;
    }

    void traverse(TreeNode* node, int& count, int max){
        if(node == nullptr){
            return;
        }
        if(node->val >= max){
            max = node->val;
            count++;
        }
        traverse(node->left, count, max);
        traverse(node->right, count, max);
    }
};
