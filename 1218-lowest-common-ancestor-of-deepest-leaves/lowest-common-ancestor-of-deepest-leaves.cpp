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
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if (!root) return {0, nullptr};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int leftDepth = left.first;
        int rightDepth = right.first;

        // Case 1: Both subtrees are equally deep
        if (leftDepth == rightDepth) {
            return {leftDepth + 1, root};
        }
        
        // Case 2: Left subtree is deeper
        if (leftDepth > rightDepth) {
            return {leftDepth + 1, left.second};
        }

        // Case 3: Right subtree is deeper
        return {rightDepth + 1, right.second};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second;
    }
};