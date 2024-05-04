/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:
    Node *createTree(int in[], int post[], int l, int r, int&postIdx) {
        if(l > r) return NULL;
        
        Node * node = new Node(post[postIdx--]);
        
        int idx;
        for(int i = l; i <= r; i++) {
            if(in[i] == node->data) {
                idx = i;
                break;
            }
        }
        
        node->right = createTree(in, post, idx+1, r, postIdx);
        node->left = createTree(in, post, l, idx-1, postIdx);
        
        return node;
    }
    
    Node *buildTree(int in[], int post[], int n) {
        int postIdx = n-1;
        Node * res = createTree(in, post, 0, n-1, postIdx);
        return res;
    }
};
