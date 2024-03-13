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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0)
            return NULL;
        
        return build(preorder,0,preorder.size()-1);
    }
    TreeNode* build(vector<int> preorder,int prestart, int preend){
        if(prestart>preend)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[prestart]);  
        int nleft = 0;   
        for(int i=prestart+1; i<=preend; i++){
            if(preorder[i]<root->val)
                nleft++;
            else
                break;
        }
        root->left = build(preorder,prestart+1,prestart+nleft);
        root->right = build(preorder,prestart+nleft+1,preend);

        return root;
    }
};