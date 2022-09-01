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
    void solve(TreeNode *root, int &ans, int mx){
        if(root==NULL)
            return;
        mx = max(mx, root->val);
        if(mx <= root->val){
            ans++;
        }
        solve(root->left, ans, mx);
        solve(root->right, ans, mx);
        
    }
    int goodNodes(TreeNode* root) {
        int ans = 0;
        solve(root, ans, INT_MIN);
        return ans;
    }
};