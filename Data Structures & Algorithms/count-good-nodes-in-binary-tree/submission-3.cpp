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
    int result = 0;
    int goodNodes(TreeNode* root) {
        traverse(root, root->val);
        return result;
    }

private:
    void traverse(TreeNode* root, int max){
        if(root == nullptr){
            return;
        }
        if(root->val >= max){
            result++;
            traverse(root->left, root->val);
            traverse(root->right, root->val);
        }else{
            traverse(root->left, max);
            traverse(root->right, max);
        }
        
    }

};
