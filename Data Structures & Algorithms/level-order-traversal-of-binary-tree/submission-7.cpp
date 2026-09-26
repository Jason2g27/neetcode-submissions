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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> results;
        dfs(root, results, 0);
        return results;
    }

    void dfs(TreeNode* node, vector<vector<int>>& results, int level) {
        if(node == nullptr){
            return;
        }
        if(level == results.size()){
            results.push_back(vector<int>());
        }
        results[level].push_back(node->val);
        dfs(node->left, results, level+1);
        dfs(node->right, results, level+1);
    }
};
