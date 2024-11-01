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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        TreeNode* curr = root;
        TreeNode* prev = curr;
        if(curr == NULL) return node;
        while(true){
            prev = curr;
            if(curr->val < val){
                curr = curr->right;
                if(curr == NULL){
                    prev->right = node;
                    break;
                }
            }else{
                curr = curr->left;
                if(curr == NULL){
                    prev->left = node;
                    break;
                }
            }
        }
        return root;

    }
};