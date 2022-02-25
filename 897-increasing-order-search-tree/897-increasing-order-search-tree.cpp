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
    void inorder(vector<int>&ans, TreeNode *root)
    {
        if(root==NULL)return;
        inorder(ans, root->left);
        ans.push_back(root->val);
        inorder(ans,root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>ans;
        inorder(ans, root);
        TreeNode *head = NULL;
        if(ans.empty()==false)
        {
            head = new TreeNode(ans[0]);
            TreeNode *curr = head;
            ans.erase(ans.begin()+0);
            for(auto x:ans)
            {
                curr->right = new TreeNode(x);
                curr->left = NULL;
                if(curr->right)curr = curr->right;
            }
        }
        else return NULL;
        return head;
     }
};