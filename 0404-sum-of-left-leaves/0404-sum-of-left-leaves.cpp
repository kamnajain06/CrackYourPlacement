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
    void preOrder(TreeNode* root, int &sum, bool flag){
        if(root == NULL) return;

        if(root->left == NULL && root->right == NULL && flag == 0) sum+=root->val;

        preOrder(root->left,sum,0);
        preOrder(root->right,sum,1);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(root->left == NULL && root->right == NULL) return 0;
        preOrder(root,sum,0);
        return sum;
    }
};