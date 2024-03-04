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
    void mark_parents(TreeNode *root,  unordered_map<TreeNode* ,TreeNode *> &parent_vis){
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *current = q.front();
            q.pop();
            if(current->left){
                parent_vis[current->left] = current;
                q.push(current->left);
            }
            if(current->right){
                parent_vis[current->right] = current;
                q.push(current->right);
            }
        }
    }
    vector<int> sol_distance(TreeNode* root, TreeNode* target, int k){
        unordered_map<TreeNode* ,TreeNode *> parent_vis;
        mark_parents(root,parent_vis);

        unordered_map<TreeNode* ,bool> visited;
        queue<TreeNode *> q;
        q.push(target);
        visited[target] = true;
        int current_level = 0;

        while(!q.empty()){
            int size = q.size();
            
            if(current_level++==k)
                break;

            for(int i=0; i<size; i++){
                TreeNode *current = q.front();
                q.pop();
                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right] = true;
                }
            
                if(parent_vis[current] && !visited[parent_vis[current]]){
                    q.push(parent_vis[current]);
                    visited[parent_vis[current]] = true;

                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            res.push_back(node->val);
        }
        return res;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res = sol_distance(root,target,k);
        return res;
    }
};