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
    void NodesTree(int &cnt, TreeNode* root)
    {
        if(root==NULL)return;
        cnt++;
        NodesTree(cnt,root->left);
        NodesTree(cnt,root->right);
    }
    
    int countNodes(TreeNode* root) {
        int cnt=0;
        NodesTree(cnt,root);
        return cnt;
    }
};