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

    unordered_map<int, int> inorderMap;
    int preorderIndex = 0;

    TreeNode* arrayToTree(const vector<int>& preorder, int left, int right){
        if(left > right) return nullptr;

        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);

        root->left = arrayToTree(preorder, left,inorderMap[rootValue]-1);
        root->right = arrayToTree(preorder, inorderMap[rootValue]+1, right);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0;i<inorder.size(); i++){
            inorderMap[inorder[i]] =i;

        }
        return arrayToTree(preorder, 0, inorder.size()-1);
        
    }
};