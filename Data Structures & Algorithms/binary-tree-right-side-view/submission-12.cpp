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