
vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int> res;
    queue<Node *>q;
    q.push(root);
    while(!q.empty()) {
        int sz = q.size();
        vector<int>temp;
        for(int i = 0; i < sz; i++) {
            Node * frnt = q.front();    q.pop();
            temp.push_back(frnt->data);
            if(frnt->left) { q.push(frnt->left); }
            if(frnt->right) { q.push(frnt->right); }
        }
        
        copy(res.begin(), res.end(), back_inserter(temp));
        swap(res, temp);
    }
    
    return res;
}
