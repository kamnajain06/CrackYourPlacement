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
    bool flag = 1;
    void preOrder(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL) return;
        else if(p != NULL && q == NULL || p == NULL && q != NULL ) {
            flag = 0;
            return;
        }
        else if(p->val !=  q->val) {
            flag=0;
            return;
        }
        isSameTree(p->left, q->left);
        isSameTree(p->right, q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        preOrder(p,q);
        return flag;
    }
};