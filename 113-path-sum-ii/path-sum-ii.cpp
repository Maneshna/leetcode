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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> currentPath;
        dfs(root, targetSum, currentPath, result);
        return result;
    }

private:
    void dfs(TreeNode* node, int remainingSum, vector<int>& currentPath, vector<vector<int>>& result) {
        // Base case: if the node is null, just return
        if (!node) return;

        // Add the current node's value to our path
        currentPath.push_back(node->val);

        // Check if it's a leaf node and if the remaining sum equals the node's value
        if (!node->left && !node->right && remainingSum == node->val) {
            result.push_back(currentPath);
        } else {
            // Recursively search the left and right subtrees with the updated sum
            dfs(node->left, remainingSum - node->val, currentPath, result);
            dfs(node->right, remainingSum - node->val, currentPath, result);
        }

        // Backtrack: remove the current node from the path before going back up the tree
        currentPath.pop_back();
    }
};