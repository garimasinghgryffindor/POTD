/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    
    bool preorder(Node* root, int a) {
        if(!root) return false;
        if(root->data == a) return true;
        return preorder(root->left, a) || preorder(root->right, a);
    }
    
    int height(Node* root, int a, int x) {
        if(!root) return -1;
        if(root->data == a) {
            return x;
        }
        
        int h1 = height(root->left, a, x+1);
        int h2 = height(root->right, a, x+1);
        
        if(h1 == -1) return h2;
        return h1;
    }
    
    int findDist(Node* root, int a, int b) {
        // Your code here
        
        if(root->data == a) {
            return height(root, b, 0);
        } else if(root->data == b) {
            return height(root, a, 0);
        }
        
        bool findALeft = preorder(root->left, a);
        bool findBRight = preorder(root->right, b);
        
        if(findALeft && findBRight) {
            // a on the left side and b on the right side
            int ansA = height(root, a, 0);
            int ansB = height(root, b, 0);
            return ansA + ansB;
        }
        
        if(!findALeft && !findBRight) {
            // b on the left side and a on the right side
            int ansA = height(root, a, 0);
            int ansB = height(root, b, 0);
            return ansA + ansB;
        }
        
        if(findALeft && !findBRight) {
            // a and b on the left side
            return findDist(root->left, a, b);
        } else {
            // a and b on the right side
            return findDist(root->right, a, b);
        }
    }
};
