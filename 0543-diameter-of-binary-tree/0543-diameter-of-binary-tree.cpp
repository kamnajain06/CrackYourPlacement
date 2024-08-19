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
    int maxDepth(TreeNode* root,int &ans){
        if(root == NULL) return 0;
        
        int leftNode = maxDepth(root->left,ans);
        int rightNode = maxDepth(root->right,ans);
        
        ans = max(ans,leftNode+rightNode);
        
        return 1+max(leftNode,rightNode);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        maxDepth(root,ans);
        return ans;
    }
};