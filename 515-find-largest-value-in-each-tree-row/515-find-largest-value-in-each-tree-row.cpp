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
    vector<int> largestValues(TreeNode* root) {
        vector<int>v;
        if(root==NULL)return v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int cnt = q.size();
            int mx = INT_MIN;
            for(int i=0; i<cnt; i++)
            {
                auto curr = q.front();
                q.pop();
                mx = max(curr->val, mx);
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            v.push_back(mx);
        }
        return v;
    }
};