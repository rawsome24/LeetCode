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
    void inorder(TreeNode *root, vector<string>&v, string str)
    {
        if(root==NULL)return;
        if(root->left==NULL && root->right==NULL)
        {
            str.append(to_string(root->val));
            v.push_back(str);
            // return;
        }
        str+=to_string(root->val)+"->";
        inorder(root->left,v,str);
        inorder(root->right,v,str);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>v;
        string str = "";
        inorder(root,v,str);
        return v;
    }
};