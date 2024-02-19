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
    void preorder(TreeNode *node,vector<int> &ans){
        if(node==NULL){
            ans.push_back(-1);
            return;
        }

        ans.push_back(node->val);
        preorder(node->left,ans);
        preorder(node->right,ans);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> p1;
        vector<int> q1;

        preorder(p,p1);
        preorder(q,q1);

        if(p1==q1)
            return true;
        
        return false;
    }
};