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
    int preIdx = 0;
    int inIdx = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return traverse(preorder, inorder, INT_MAX);
    }

    TreeNode* traverse(vector<int>& preorder, vector<int>& inorder, int bound){
        if(preIdx >= preorder.size()){
            return nullptr;
        }
        if(inorder[inIdx] == bound){
            inIdx++;
            return nullptr;
        }
        TreeNode* cur = new TreeNode(preorder[preIdx++]);
        cur->left = traverse(preorder, inorder, cur->val);
        cur->right = traverse(preorder, inorder, bound);
        return cur;
    }
};
