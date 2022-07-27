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
    void preOrder(TreeNode *root, vector<int>&v){
        if(root==NULL)
            return;
        v.push_back(root->val);
        preOrder(root->left, v);
        preOrder(root->right, v);
    }
    void flatten(TreeNode* root) {
        vector<int>v;
        preOrder(root, v);
        if(v.size()>=1){
            // cout<<v.size()<<endl;
            TreeNode *tail = NULL/*, *newRoot=NULL*/;
            for(int i=0; i<v.size(); i++){
                if(tail == NULL){
                    root->val = v[0];
                    root->left = NULL;
                    tail = root;
                    tail->left = NULL;
                    // nR = temp;
                    // root = nR;
                }
                else
                {
                    TreeNode *temp = new TreeNode(v[i]);
                    tail->right = temp;
                    tail->left = NULL;
                    tail = tail->right;
                }
                // delete temp;
            }
        }
        
    }
};