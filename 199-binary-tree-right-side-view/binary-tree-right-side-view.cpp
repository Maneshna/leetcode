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

    void solve(TreeNode* node, int depth, vector<int>&ans){
        if(node ==  NULL) return;
        if(depth == ans.size()){
            ans.push_back(node->val);
        }
        //go to the right side to check 

        solve(node->right, depth+1, ans);

        //go to the left side

        solve(node->left, depth+1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        solve(root, 0, ans);
        return ans;
        
    }
};