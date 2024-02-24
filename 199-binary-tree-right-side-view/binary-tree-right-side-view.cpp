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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ds;
        fun(root,0,ds);
        return ds;
    }
    void fun(TreeNode *node,int level,vector<int> &ds){
        if(node==NULL)
            return;
        
        if(level==ds.size())
            ds.push_back(node->val);
        
        fun(node->right,level+1,ds);
        fun(node->left,level+1,ds);
    }
};