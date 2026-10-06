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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int x = 0, y = 0;
        return traverse(preorder, inorder, x, y, INT_MAX);
    }

    TreeNode* traverse(vector<int>& preorder, vector<int>& inorder, int& i, int& j, int bound){
        if(i >= preorder.size()){
            return nullptr;
        }
        if(inorder[j] == bound){
            j++;
            return nullptr;
        }
        TreeNode* cur = new TreeNode(preorder[i++]);
        cur->left = traverse(preorder, inorder, i, j, cur->val);
        cur->right = traverse(preorder, inorder, i, j, bound); 
        return cur;
    }
};
