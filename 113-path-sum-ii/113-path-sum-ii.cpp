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
    void solve(TreeNode* root, int x, vector<pair<TreeNode*,int>>v, vector<vector<int>>&ans, set<vector<pair<TreeNode*,int>>>&st){
        if(root==NULL)
            return;
        if(x-root->val==0 and root->left==NULL and root->right==NULL){
            v.push_back({root,root->val});
            if(st.find(v)==st.end()){
                vector<int>res;
                for(int i=0; i<v.size(); i++){
                    res.push_back(v[i].second);
                }
                ans.push_back(res);
            }
            st.insert(v);
            return;
        }
        v.push_back({root,root->val});
        solve(root->left, x-root->val, v, ans, st);

        solve(root->right, x-root->val, v, ans, st);
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        set<vector<pair<TreeNode*,int>>>st;
        vector<pair<TreeNode*,int>>v;
        vector<vector<int>>ans;
        if(targetSum==0 and root==NULL)
            return ans;
        solve(root, targetSum, v, ans, st);
        return ans;
    }
    
};