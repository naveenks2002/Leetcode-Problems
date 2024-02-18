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
    int maxPathSum(TreeNode* root) {
        getval(root);
        return maxi;
    }   
    int getval(TreeNode* node){
        
        if(node==NULL)
            return 0;
        
        int leftsum = getval(node->left);
        int rightsum = getval(node->right);

        maxi = max(maxi,leftsum + rightsum + node->val);

        int val = node->val + max(leftsum,rightsum);

        if(val<0)
            return 0;

        else
            return val;
    }
};