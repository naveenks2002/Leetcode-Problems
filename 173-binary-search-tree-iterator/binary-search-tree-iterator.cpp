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
class BSTIterator {
public:
    vector<int> inorder;
    int i = 0;
    BSTIterator(TreeNode* root) {
        traversal(root);
    }
    void traversal(TreeNode* root){
        if(root==NULL)
            return ;
        
        traversal(root->left);
        inorder.push_back(root->val);
        traversal(root->right);
    }
    int next() {
        int x  = inorder[i];
        i++;
        return x;
    }
    
    bool hasNext() {
        if(i==inorder.size())
            return false;

        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */