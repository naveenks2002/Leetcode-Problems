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
    int burn(unordered_map<TreeNode *, TreeNode *> parent, TreeNode* start){
        unordered_map<TreeNode *, bool> vis;
        vis[start] = true;
        queue<TreeNode *> q;
        q.push(start);
        int maxi = 0;
        while(!q.empty()){
            int size = q.size();
            int flag = 0;
            for(int i=0; i<size; i++){
                TreeNode* node  = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    flag = 1;
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if(node->right && !vis[node->right]){
                    flag = 1;
                    q.push(node->right);
                    vis[node->right] = true;
                } 
                if(parent[node] && !vis[parent[node]]){
                    flag = 1;
                    q.push(parent[node]);
                    vis[parent[node]] = true;
                }
            }
            if(flag)
                maxi++;
        }
        return maxi;
    }
    TreeNode* mark_parents(unordered_map<TreeNode *, TreeNode *> &parent,TreeNode* root,int start){
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *res;
        while(!q.empty()){
            TreeNode* current = q.front();
            if(current->val==start) 
                res = current;
            q.pop();
            if(current->left){
                parent[current->left] = current;
                q.push(current->left); 
            }
            if(current->right){
                parent[current->right] = current;
                q.push(current->right); 
            }
        }
        return res;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode *, TreeNode *> parent;
        TreeNode* res = mark_parents(parent,root,start);
        int ans = burn(parent,res);
        return ans;
    }
};