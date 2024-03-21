vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int>res;
    	queue<Node*>q;
    	bool flow = true; // right
    	q.push(root);
    	
    	while(!q.empty()) {
    	    int sz = q.size();
    	    vector<int>temp;
    	    
    	    for(int i = 0; i < sz; i++) {
    	        auto ptr = q.front();   q.pop();
    	        temp.push_back(ptr->data);
    
	            if(ptr->left) {
	                q.push(ptr->left);
	            }
	            if(ptr->right) {
	                q.push(ptr->right);
	            }
    	    }
    	    
    	    if(flow) {
    	        for(int i = 0; i < temp.size(); i++) {
    	            res.push_back(temp[i]);
    	        }
    	    } else {
    	        for(int i = temp.size()-1; i >= 0; i--) {
    	            res.push_back(temp[i]);
    	        }
    	    }
    	    
    	    flow = !flow;
    	}
    	
    	return res;
    }
