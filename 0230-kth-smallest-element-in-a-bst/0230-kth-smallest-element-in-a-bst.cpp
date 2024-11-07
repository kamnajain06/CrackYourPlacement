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
    void inorder(TreeNode* root, vector<int> &trav, int k){
        if(root == NULL) return;
        inorder(root->left,trav,k);
        trav.push_back(root->val);
        if(trav.size() == k) return;
        inorder(root->right,trav,k);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> trav;
        inorder(root,trav,k);
        return trav[k-1];
    }
};