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
    int cnt = 0;
    void inorder(TreeNode* root, vector<int> &ans){
        if(root==NULL)
            return;

        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);

    }
    void newinorder(TreeNode* node,vector<int> ans){
        if(node==NULL)
            return;
        
        newinorder(node->left,ans);
        if(node->val!=ans[cnt])
            node->val = ans[cnt];
        cnt++;
        newinorder(node->right,ans);
    }
    void recoverTree(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        sort(ans.begin(),ans.end());
    
        newinorder(root,ans);
    }
};