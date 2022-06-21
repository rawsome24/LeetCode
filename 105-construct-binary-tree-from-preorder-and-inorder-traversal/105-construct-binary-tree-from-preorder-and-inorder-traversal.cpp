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
    int preIndex = 0;
    TreeNode* solve(vector<int>&pre, vector<int>&in, int is, int ie){
        if(is>ie)
            return NULL;
        TreeNode *root = new TreeNode(pre[preIndex++]);
        int ind;
        for(int i=is; i<=ie; i++){
            if(in[i]==root->val){
                ind = i;
                break;
            }
        }
        root->left = solve(pre, in, is, ind-1);
        root->right = solve(pre, in, ind+1, ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        return solve(pre, in, 0, in.size()-1);
    }
};