//User function Template for C++

/* Node of the binary search tree 
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution
{
public:
    
    Node * dummy = new Node(0);
    Node * prev = dummy;
    
    void recur(Node* root) {
        if(!root) return;
        
        recur(root->left);
        
        Node * newNode = new Node(root->data);
        prev->right = newNode;
        prev = newNode;
        
        recur(root->right);
        
        // return newNode;
    }
    
    Node *flattenBST(Node *root)
    {
        // code here
        recur(root);
        return dummy->right;
    }
};
