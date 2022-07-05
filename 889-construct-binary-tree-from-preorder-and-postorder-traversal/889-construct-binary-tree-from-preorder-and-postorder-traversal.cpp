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
    int pre=0;
    TreeNode* solve(vector<int>&preorder, int is, int ie, vector<int>&post){
        if(is>ie or pre>=preorder.size())
            return NULL;
        TreeNode *root = new TreeNode(preorder[pre++]);
        if(pre==preorder.size() or is==ie)
            return root;
        int i;
        for(i=is; i<=ie; i++){
            if(preorder[pre]==post[i])
                break;
        }
        if(i<=ie){
            root->left = solve(preorder, is, i, post);
            root->right = solve(preorder, i+1, ie-1, post);
        }
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return solve(preorder, 0, preorder.size()-1, postorder);
    }
};