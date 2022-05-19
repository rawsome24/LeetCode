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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
       queue<TreeNode *>q;
        q.push(root);
        int j=0;
        
        while(!q.empty()){
            int cnt = q.size();
            vector<int>v;
            for(int i=0; i<cnt; i++){
                auto node = q.front();
                q.pop();
                v.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(j%2)reverse(v.begin(),v.end());
            ans.push_back(v);
            j++;
        }
        return ans;
    }
};