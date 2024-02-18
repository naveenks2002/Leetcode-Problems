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
    void find_max(TreeNode* node){
        if(node==NULL)
            return ;

        int lh = getHeight(node->left);
        int rh = getHeight(node->right);

        maxi = max(maxi,lh + rh);
        
        find_max(node->left);
        find_max(node->right);
    }
    int getHeight(TreeNode* node){
        if(node==NULL)
            return 0;

        int lh = getHeight(node->left);
        int rh = getHeight(node->right);

        return 1 + max(lh,rh);
    }

};