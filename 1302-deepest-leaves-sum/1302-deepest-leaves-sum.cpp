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
    int height(TreeNode *root)
    {
        if(root==NULL)return 0;
        return 1+max(height(root->left),height(root->right));
    }
    void inorder(TreeNode *root, int &sum,int cnt, int h)
    {
        if(root==NULL)return;
        if(root->left==NULL && root->right==NULL && h==cnt)
            {sum+=root->val; return;}
        inorder(root->left,sum,cnt+1,h);
        inorder(root->right,sum,cnt+1,h);
    }
    int deepestLeavesSum(TreeNode* root) {
        int sum=0,cnt=1;
        int h = height(root);
        // return h;
        inorder(root,sum,cnt,h);
        return sum;
    }
};