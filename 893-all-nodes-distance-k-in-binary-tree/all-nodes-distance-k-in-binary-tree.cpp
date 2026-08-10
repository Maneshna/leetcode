/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void makeParent(TreeNode* node, TreeNode* par, unordered_map<TreeNode*, TreeNode*>&parent){
        if(node==NULL){
            return;
        }

        parent[node] = par;

        makeParent(node->left, node, parent);
        makeParent(node->right, node, parent);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*, TreeNode*> parent;

        //store the parent of every node in this hasahmap
        makeParent(root, NULL, parent);

        //bfs from target to get all the nodes up down left right 
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int distance = 0;

        while(!q.empty()){
            int size =q.size();

            //we have reached the distace so stop there
            if(distance == k){
                vector<int> ans;
                while(!q.empty()){
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }

            //process current level again

            for(int i =0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                //left
                if(node->left &&
                   !visited.count(node->left))
                {
                    q.push(node->left);
                    visited.insert(node->left);
                }

                //right
                if(node->right && !visited.count(node->right)){
                    q.push(node->right);
                    visited.insert(node->right);
                }

                if (parent[node] && !visited.count(parent[node])){
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }
            distance++;
        }
        return {};
        
    }
};