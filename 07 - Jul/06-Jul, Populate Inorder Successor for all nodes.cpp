/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
*/
class Solution {
  public:
    void inorder(Node* root, vector<Node*>&ind) {
        if(!root) return;
        inorder(root->left, ind);
        ind.push_back(root);
        inorder(root->right, ind);
    }
    
    void populateNext(Node *root) {
        vector<Node*>ind;
        inorder(root, ind);
        
        int n = ind.size();
        for(int i = 0; i < n-1; i++) {
            ind[i]->next = ind[i+1];
        }
    }
};
