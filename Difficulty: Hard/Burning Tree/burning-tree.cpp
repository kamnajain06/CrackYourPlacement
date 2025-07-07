/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    unordered_map<Node*, Node*> parent;
    unordered_map<Node*, int> visited;

    void markParent(Node* root){
        if(root == nullptr) return;
        if(root->left){
            parent[root->left] = root;
            markParent(root->left);
        }
        if(root->right){
            parent[root->right] = root;
            markParent(root->right);
        }
    }
    Node* returnTarget(Node* root, int target){
        if(root == nullptr) return nullptr;
        if(root->data == target) return root;
        
        Node* leftSubTree = returnTarget(root->left, target);
        if(leftSubTree) return leftSubTree;
        Node* rightSubTree = returnTarget(root->right, target);
        return rightSubTree;
    }
    int minTime(Node* root, int target) {
        // code here
        markParent(root);
        queue<Node*> q;
        Node* t = returnTarget(root, target);
        q.push(t);
        int dis = 0;
        visited[t] = 1;
        
        while(!q.empty()){
            int size = q.size();
            dis++;
            for(int i=0; i<size; i++){
                Node* node = q.front();
                q.pop();
                if(parent.find(node) != parent.end() && visited.find(parent[node]) == visited.end()){
                    visited[parent[node]]++;
                    q.push(parent[node]);
                }
                if(node->left && visited.find(node->left) == visited.end()){
                    q.push(node->left);
                    visited[node->left]++;
                }
                if(node->right && visited.find(node->right) == visited.end()){
                    q.push(node->right);
                    visited[node->right]++;
                }
            }
        }
        return dis-1;
    }
};