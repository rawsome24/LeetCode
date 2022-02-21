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
    
    int findBottomLeftValue(TreeNode* root) {
        int h = height(root);
        queue<TreeNode*>q;
        q.push(root);
        int hT=1;
        while(!q.empty())
        {
            int cnt = q.size();
            for(int i=0; i<cnt; i++)
            {
                auto curr = q.front();
                q.pop();
                if(hT==h && i==0)return curr->val;
                if(curr->left!=NULL)q.push(curr->left);
                if(curr->right!=NULL)q.push(curr->right);
            }
            hT++;
        }
        return 0;
    }
};