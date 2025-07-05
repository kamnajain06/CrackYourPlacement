/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> leftBoundary;
    vector<int> leaves;
    vector<int> rightBoundary;
    
    void traversalLeft(Node * root){
        Node* curr = root->left;
        while(curr != nullptr){
            if(!(curr->left == nullptr && curr->right == nullptr)){
                leftBoundary.push_back(curr->data);
            }
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
        
    }
    void traversalRight(Node * root){
        Node* curr = root->right;
        while(curr != nullptr){
            if(!(curr->left == nullptr && curr->right == nullptr)){
                rightBoundary.push_back(curr->data);
            }
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        reverse(rightBoundary.begin(), rightBoundary.end());
        return;
    }
    void trav(Node * root){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr){
            leaves.push_back(root->data);
        }
        trav(root->left);
        trav(root->right);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        if(root == nullptr) return {-1};
        vector<int> ans;
        traversalLeft(root);
        traversalRight(root);
        trav(root);
        for(int i=0; i<leftBoundary.size(); i++){
            ans.push_back(leftBoundary[i]);
        }
        for(int i=0; i<leaves.size(); i++){
            ans.push_back(leaves[i]);
        }
        for(int i=0; i<rightBoundary.size(); i++){
            ans.push_back(rightBoundary[i]);
        }
        if(root->left == nullptr && root->right == nullptr){
            return {root->data};
        }
        ans.insert(ans.begin(), root->data);
        return ans;
    }
};