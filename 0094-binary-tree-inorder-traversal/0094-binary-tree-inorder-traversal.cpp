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
    vector<int> inorderTraversal(TreeNode* root) {

        // Using Morris Traversal - threaded binary tree
        vector<int> ans;
        TreeNode* curr = root;

        while(curr != NULL){
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }else{
                    prev->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;

        // Using Stack
        
        // vector<int> v;
        // stack<TreeNode*> st;
        
        // TreeNode* node = root;
        // while(true){
        //     if(node != NULL){
        //         st.push(node);
        //         node = node->left;
        //     }else{
        //         if(st.empty()) break;
        //         node = st.top();
        //         v.push_back(node->val);
        //         st.pop();
        //         node = node->right;
        //     }
        // }
        // return v;
    }
};
