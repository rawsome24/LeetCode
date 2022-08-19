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
    int fun(TreeNode* root,int &ans)
{
    if(root == NULL)
        return 0;
    int l = fun(root -> left,ans);
    int r = fun(root -> right,ans);
    if(l != 0)
        ans+=abs(l);
    if(r != 0)
        ans+=abs(r);
    return (l+r+1-root->val);
}
    
    int distributeCoins(TreeNode* root) {
        int cnt=0;
        fun(root,cnt);
        return cnt;
    }
};