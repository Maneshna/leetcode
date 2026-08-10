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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            bool foundX = false;
            bool foundY = false;

            for(int i =0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left){
                    if(node->left->val==x)
                        foundX= true;
                    if(node->left->val==y)
                        foundY = true;

                    q.push(node->left);
                }

                if(node->right){
                    if(node->right->val == x)
                        foundX= true;

                    if(node->right->val == y)
                        foundY = true;

                    q.push(node->right);
                }

                if(node->left && node->right){
                    if((node->left->val == x && node->right->val == y) || (node->right->val ==x && node->left->val ==y)){
                        return false;
                    }
                }
            }
            if(foundX && foundY){
                return true;
            }
            if(foundX || foundY){
                return false;
            }
        }
        return false;
        
    }
};