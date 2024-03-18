/* A binary tree Node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */


class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
        vector<int> res;
        
        Node * node = root;
        queue<Node *> q;
        q.push(root);
        
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                Node * x = q.front();   q.pop();
                res.push_back(x->data);
                if(x->left) {
                    q.push(x->left);
                }
                if(x->right) {
                    q.push(x->right);
                }
            }
        }
        
        return res;
    }
};
