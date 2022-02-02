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
    /*void NodesTree(int &cnt, TreeNode* root)
    {
        if(root==NULL)return;
        cnt++;
        NodesTree(cnt,root->left);
        NodesTree(cnt,root->right);
    }*/
    
    int countNodes(TreeNode* root) {
        int hl=0,hr=0;
        TreeNode *curr = root;
        if(curr==NULL)return 0;
        while(curr){hl++; curr=curr->left;}
        curr=root;
        while(curr){hr++; curr=curr->right;}
        if(hl==hr)return pow(2,hl)-1;
        
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};