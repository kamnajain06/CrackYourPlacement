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
    bool flag = false;
    int count = 0;
    void postOrder(TreeNode* root, int targetSum){
        // count++;
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL && targetSum == root->val) flag=1;
        postOrder(root->left, targetSum-root->val);
        postOrder(root->right, targetSum-root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        // if(root->left == NULL && root->right == NULL && root->val == targetSum) return true;
        postOrder(root,targetSum);
        return flag;
    }
};