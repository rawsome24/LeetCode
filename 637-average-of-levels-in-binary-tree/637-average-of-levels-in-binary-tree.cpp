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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            double cnt = q.size();
            double sum = 0;
            for(int i=0; i<cnt; i++){
                auto node = q.front();
                q.pop();
                sum+=node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            ans.push_back((double)sum/double(cnt));
        }
        return ans;
    }
};