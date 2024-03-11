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
    void insert(TreeNode *node,int val){
        if(val>node->val){
            if(node->right==NULL){
                TreeNode* newnode = new TreeNode(val);
                node->right = newnode;
                return;
            }
            else
             insert(node->right,val);
        }
        else if(val<node->val){
            if(node->left==NULL){
                TreeNode* newnode = new TreeNode(val);
                node->left = newnode;
                return;
            }
            else
             insert(node->left,val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) {
            TreeNode* node = new TreeNode(val);
            root=node;
            return root;
        }
        insert(root,val);  
        return root;
    }
};