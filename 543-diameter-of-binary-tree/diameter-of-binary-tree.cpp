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
    int maxi = INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {
        find_max(root);
        return maxi;
    }   
    int find_max(TreeNode* node){
        if(node==NULL)
            return 0;
        
        int lh = find_max(node->left);
        int rh = find_max(node->right);

        maxi = max(maxi,lh + rh);
        
        return 1 + max(lh,rh);
    }
};