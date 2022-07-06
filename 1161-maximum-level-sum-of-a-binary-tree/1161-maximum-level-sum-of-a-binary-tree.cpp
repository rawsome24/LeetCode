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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ans = INT_MIN;
        int ind = 1;
        int res = 0;
        while(!q.empty()){
            int sum = 0;
            int cnt = q.size();
            for(int i=0; i<cnt; i++){
                auto node = q.front();
                q.pop();
                sum+=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(sum>ans){
                res = ind;
                ans = sum;
            }
            ind++;
        }
        return res;
    }
    
};