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
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int leftHeight =0;
        TreeNode* leftNode =root;
        while(leftNode != nullptr){
            leftHeight++;
            leftNode = leftNode ->left;
        }

        int rightHeight =0;
        TreeNode* rightNode = root;
        while(rightNode != nullptr){
            rightHeight++;
            rightNode = rightNode->right;
        }

        if(leftHeight == rightHeight){
            return (1<< leftHeight)-1;
        }

        return 1+countNodes(root->left)+ countNodes(root->right);
        
    }
};