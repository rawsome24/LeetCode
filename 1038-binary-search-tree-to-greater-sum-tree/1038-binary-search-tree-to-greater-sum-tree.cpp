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
    void traverse(TreeNode *root, int &data)
    {
        if(root==NULL)return;
        traverse(root->right,data);
        root->val += data;
        data = root->val;
        traverse(root->left,data);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int data = 0;
        traverse(root,data);
        return root;
    }
};