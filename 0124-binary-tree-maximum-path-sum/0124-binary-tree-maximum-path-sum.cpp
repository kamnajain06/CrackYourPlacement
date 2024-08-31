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
    int ans = INT_MIN;
    int maxDepth(TreeNode* root){
        if(root == NULL) return 0;
        int leftValue = max(0,maxDepth(root->left));
        int rightValue = max(0,maxDepth(root->right));
        ans = max(ans, root->val+leftValue+rightValue);
        return root->val+max(leftValue,rightValue);
    }
    int maxPathSum(TreeNode* root) {
        maxDepth(root);
        return ans;
    }
};