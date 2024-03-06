class Solution{
    public:
    bool postorder(Node *root) {
        if(!root) return true;
        
        if(!root->left && !root->right) return true;
        
        if(!postorder(root->left)) return false;
        
        if(!postorder(root->right)) return false;
        
        int sum = 0;
        if(root->left) {
            sum+=root->left->data;
        }
        if(root->right) {
            sum+=root->right->data;
        }
        
        if(sum == root->data) return true;
        return false;
    }
    
    int isSumProperty(Node *root)
    {
        if(postorder(root)) return 1;
        return 0;
    }
};
