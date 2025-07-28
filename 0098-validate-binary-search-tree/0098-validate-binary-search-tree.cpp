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

    long long val = LLONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        bool leftValue = isValidBST(root->left);
        if(root->val <= val) return false;
        else{
            val = root->val;
        }
        bool rightValue = isValidBST(root->right);
        return leftValue && rightValue;
    }
};