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
    void preorder(TreeNode* root, vector<int> &ans){
        if(root==NULL)
            return;
        
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        preorder(root,ans);

        sort(ans.begin(),ans.end());

        for(int i=0; i<ans.size(); i++){
            if(k-1==i)
                return ans[i];
        }
        return -1;
    }
};