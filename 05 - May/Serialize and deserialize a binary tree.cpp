/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */


class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    void serialUtils(Node* root, vector<int>&res) {
        if (!root) return;
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()) {
            Node * curr = q.front();    q.pop();
            
            if(curr) {
                q.push(curr->left);
                q.push(curr->right);
                res.push_back(curr->data);
            } else {
                res.push_back(INT_MIN);
            }
        }
    }
    
    vector<int> serialize(Node *root) 
    {
        vector<int>res;
        serialUtils(root, res);
        return res;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
        if(A.empty() || A[0] == INT_MIN) return NULL;
        
        Node * root = new Node(A[0]);
        queue<Node*>q;
        q.push(root);
        int i = 1, n = A.size();
        while(!q.empty() && i < n) {
            Node * curr = q.front();    q.pop();
            
            if(i < n && A[i] != INT_MIN) {
                curr->left = new Node(A[i]);
                q.push(curr->left);
            }
            i++;
            
            if(i < n && A[i] != INT_MIN) {
                curr->right = new Node(A[i]);
                q.push(curr->right);
            }
            i++;
        }
        
        return root;
    }

};
