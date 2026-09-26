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
        vector<int> results;
        int depth = 0;
        traverse(root, results, depth);
        return results;
    }

    void traverse(TreeNode* node, vector<int>& results, int depth){
        if(!node){
            return;
        }
        if(results.size() == depth){
            results.push_back(node->val);
        }
        traverse(node->right, results, depth+1);
        traverse(node->left, results, depth+1);
    }
};
