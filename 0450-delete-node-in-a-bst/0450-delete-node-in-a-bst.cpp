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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* prev = NULL;
        TreeNode* curr = root;
        TreeNode* temp = NULL;
        while(curr != NULL){
            if(curr->val == key){
                if(prev == NULL){
                    temp = curr->right;
                    if(curr->left){
                        TreeNode* modifiedRoot = curr->left;
                        curr = curr->left;
                        while(curr && curr->right != NULL){
                            curr = curr->right;
                        }
                        if(curr) curr->right = temp;
                        return modifiedRoot;
                    }else{
                        return curr->right;
                    }
                }else if(prev->left == curr){
                    prev->left = curr->left;
                    if(curr->right){
                        temp = curr->right;
                    }
                    curr = curr->left;
                    while(curr && curr->right != NULL){
                        curr = curr->right;
                    }
                    if(curr) curr->right = temp;
                    else prev->left = temp;
                }else{
                    prev->right = curr->right;
                    if(curr->left){
                        temp = curr->left;
                    }
                    curr = curr->right;
                    while(curr && curr->left != NULL){
                        curr = curr->left;
                    }
                    if(curr) curr->left = temp;
                    else prev->right = temp;
                }
                return root;
            }
            else if(curr->val < key){
                prev = curr;
                curr = curr->right;
            }else{
                prev = curr;
                curr = curr->left;
            }
        }
        return root;
    }
};