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

    int maxDepth(TreeNode* root, bool &flag){
        if(root == NULL) return 0;
        
        TreeNode* leftNode = root->left;
        TreeNode* rightNode = root->right;
        
        int leftSubtree = 1 + maxDepth(leftNode,flag);
        int rightSubtree = 1 + maxDepth(rightNode,flag);
        
        if(abs(leftSubtree-rightSubtree) > 1){
            flag = false;
        }
        
        return max(leftSubtree,rightSubtree);
        
    }
    bool isBalanced(TreeNode* root) {
        bool flag = true;
        maxDepth(root, flag);
        
        if(flag)return true;
        return false;
    }
};