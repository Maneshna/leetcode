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
    unordered_map<int, int> inorderMap;
    int postIndex = 0;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i =0; i<inorder.size(); i++){
            inorderMap[inorder[i]] =i;

        }
        postIndex = postorder.size() -1;
        return arrayToTree(postorder, 0, inorder.size()-1);
        
    }

private:
    TreeNode* arrayToTree(vector<int>& postorder, int left, int right){
        if(left > right) return nullptr;

        int rootValue= postorder[postIndex--];
        TreeNode* root = new TreeNode(rootValue);

        root->right = arrayToTree(postorder, inorderMap[rootValue]+1, right);
        root->left  = arrayToTree(postorder, left, inorderMap[rootValue]-1);

        return root;
    }
};