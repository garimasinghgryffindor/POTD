

//User function Template for C++

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

vector<int> noSibling(Node* node)
{
    vector<int> res;
    
    queue<Node*> q;
    q.push(node);
    
    while(!q.empty()) {
        int sz = q.size();

        for(int i = 0; i < sz; i++) {
            Node * frnt = q.front();    q.pop();
            if(frnt->left) {
                q.push(frnt->left);
            }
            if(frnt->right) {
                q.push(frnt->right);
            }
            
            if(frnt->left && !frnt->right) {
                res.push_back(frnt->left->data);
            } else if(frnt->right && !frnt->left) {
                res.push_back(frnt->right->data);
            }
        }
    }
    sort(res.begin(), res.end());
    
    if(res.empty()) {
        res.push_back(-1);
    }
    
    return res;
}

