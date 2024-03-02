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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)  
            return 0;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        long long ans = 0;     
        while(!q.empty()){
            TreeNode* node = q.front().first;
            long long size = q.size();
            long long first,last;
            long long mini = q.front().second;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front().first;
                long long curr_id = q.front().second - mini;
                q.pop();
                if(i==0) first = curr_id;
                if(i==size-1) last = curr_id;
                
                if(node->left)
                    q.push({node->left,curr_id*2+1});
                
                if(node->right)   
                    q.push({node->right,curr_id*2+2});
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};