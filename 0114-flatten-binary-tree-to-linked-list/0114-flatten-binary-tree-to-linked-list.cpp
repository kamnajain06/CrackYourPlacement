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

    // In-space - Recursive Solution
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
        return;
    }

// In-space - Iterative Solution
// void flatten(TreeNode* root) {
//         stack<TreeNode*> st;
//         if(root == NULL) return;
//         st.push(root);

//         while(!st.empty()){
//             TreeNode* curr = st.top();
//             st.pop();

//             if(curr->right != NULL) st.push(curr->right);
//             if(curr->left != NULL) st.push(curr->left);

//             if(!st.empty()){
//                 curr->right = st.top();  
//             }
//             curr->left = NULL;
//         }
//         return;
//     }

    //extra space 
    // vector<TreeNode*> v;
    // void preorder(TreeNode* root){
    //     if(root == NULL) return;
    //     v.push_back(root);
    //     preorder(root->left);
    //     preorder(root->right);
    // }
    // void flatten(TreeNode* root) {
    //     int i = 1;
    //     preorder(root);
    //     for(auto it:v){
    //         cout<<it->val<<endl;
    //     }
    //     while( i < v.size()){
    //         root->left = NULL;
    //         root->right = v[i];
    //         root = root->right;
    //         i++;
    //     }
    //     return;
    }
};
