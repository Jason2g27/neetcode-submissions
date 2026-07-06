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
        vector<int> result;
        int depth = 0;
        traverse(root, depth, result);
        return result;
    }

private:
    void traverse(TreeNode* root, int depth, vector<int>&result){
        if(root == nullptr){
            return;
        }
        if(result.size() == depth){
            result.push_back(root->val);
        }
        traverse(root->right, depth+1, result);
        traverse(root->left, depth+1, result);
    }
};
