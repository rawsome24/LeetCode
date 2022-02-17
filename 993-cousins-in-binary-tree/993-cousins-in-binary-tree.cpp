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
    void inorder(TreeNode *root, int x, int par, int &ans)
    {
        if(!root)return;
        if(root->val==x){ans = par;return;}
        par = root->val;
        inorder(root->left,x,par,ans);
        inorder(root->right,x,par,ans);
    }
    int depth(TreeNode *root,int x){
        if(!root)return -1;
        int dis = -1;
        
        if(root->val==x || (dis=depth(root->left,x))>=0 || (dis = depth(root->right,x))>=0)
            return dis+1;
        return dis;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        int par = 0,ans=0;
        inorder(root,x,par,ans);
        int par1 = ans;
        int h1 = depth(root,x);
        ans = 0;
        inorder(root,y,par,ans);
        int par2 = ans;
        int h2 = depth(root,y);
        
        return (par1!=par2 && h1==h2);
    }
};